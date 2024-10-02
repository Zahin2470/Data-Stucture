/*
 * Dependency:
 *   OS: windows
 *   Compiler: Have g++ follow the C++14 GNU C++ language Standard (ISO C++ plus GNU extensions) [-std=gnu++14]
 */

#include <iostream>
#include <conio.h>
#include <OS.h>
#include <algorithm>
#include <vector>
#include <io.h>
#include <fcntl.h>

using namespace std;

const int MAX_CHILD = 26;
const int SUGGESTION_LIMIT = 25;

class RadixTree
{
    class Node;
    Node *_root = nullptr;
    void print_tree(Node *, int);
    void get_entries(Node *, string, vector<string> &);
    bool search(Node *, string);
    Node *insert(Node *, string, Node *);
    Node *remove(Node *, string, Node *);

public:
    void insert(string);
    void remove(string);
    bool search(string);
    void display();
    void autocomplete(Node *, int);
    Node *root() { return _root; }
} tree;

class RadixTree::Node
{
    Node *next[MAX_CHILD]{};
    int cc = 0;
    string val;
    bool datanode;

public:
    // ctors
    Node(string value) : val(value), datanode(false) {}
    Node(string value, bool dn) : val(value), datanode(dn) {}

    Node *split(int ix, Node *parent)
    {
        if (ix < 0 || ix >= val.size())
            return this;
        Node *prefix = new Node(val.substr(0, ix));
        if (parent != nullptr)
            parent->set_child(prefix->value()[0] - 'a', prefix);
        val = val.substr(ix);
        prefix->set_child(val[0] - 'a', this); // val[0] is the edge with the parent
        return prefix;
    }

    Node *combine(Node *parent, Node *grandparent)
    {
        if (parent->child_count() != 1)
            return this;
        val = parent->value() + val;
        if (grandparent != nullptr)
            grandparent->set_child(val[0] - 'a', this);
        delete parent;
        return this;
    }

    // getter and setters
    void set_child(int ix, Node *child)
    {
        if (ix < 0 || ix >= MAX_CHILD)
            return;
        if (next[ix] == nullptr)
        {
            if (child == nullptr)
                return;
            next[ix] = child;
            cc++;
        }
        else
        {
            if (child == nullptr)
                cc--;
            next[ix] = child;
        }
    }
    Node *child(int ix)
    {
        if (ix < 0 || ix >= MAX_CHILD)
            return nullptr;
        return next[ix];
    }
    int child_count() { return cc; }
    void setdatanode(bool b) { datanode = b; }
    bool isdatanode() { return datanode; }
    string value() { return val; }
};

void RadixTree::insert(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    _root = insert(_root, str, nullptr);
}

void RadixTree::remove(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    _root = remove(_root, str, nullptr);
}

bool RadixTree::search(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return search(_root, str);
}

RadixTree::Node *RadixTree::insert(Node *root, string str, Node *parent = nullptr)
{
    if (root == nullptr)
    {
        Node *node = new Node(str);
        node->setdatanode(true);
        root = node;
        return node;
    }
    string val = root->value();
    int i = 0, lim = min(str.size(), val.size());
    while (i < lim && str[i] == val[i])
        i++;
    if (i == val.size())
    {
        if (i == str.size())
        {
            root->setdatanode(true);
            return root;
        }
        Node *child = root->child(str[i] - 'a');
        root->set_child(
            str[i] - 'a',
            insert(child, str.substr(i), root));
        return root;
    }
    root = root->split(i, parent);
    if (i == str.size())
    {
        root->setdatanode(true);
        return root;
    }
    string suffix = str.substr(i);
    root->set_child(suffix[0] - 'a', new Node(suffix, true));
    return root;
}

bool RadixTree::search(Node *root, string str)
{
    if (root == nullptr)
        return false;

    string val = root->value();
    int i = 0, lim = min(str.size(), val.size());
    while (i < lim && str[i] == val[i])
        i++;

    if (i != val.size())
        return false;

    if (i != str.size())
    {
        Node *child = root->child(str[i] - 'a');
        return search(child, str.substr(i));
    }

    return true;
}

RadixTree::Node *RadixTree::remove(Node *root, string str, Node *parent)
{
    if (root == nullptr)
        return nullptr;
    string val = root->value();
    int i = 0, lim = min(str.size(), val.size());
    while (i < lim && str[i] == val[i])
        i++;
    if (i != val.size())
        return root;
    if (i != str.size())
    {
        Node *child = root->child(str[i] - 'a');
        root->set_child(
            str[i] - 'a',
            remove(child, str.substr(i), root));
        if (!root->isdatanode() && root->child_count() == 1)
        {
            int e = 0;
            while (e < MAX_CHILD && root->child(e) == nullptr)
                e++;
            root = root->child(e)->combine(root, parent);
        }
        return root;
    }

    // root->value() == str
    root->setdatanode(false);
    if (root->child_count() == 0)
    {
        delete root;
        return nullptr;
    }
    if (root->child_count() == 1)
    {
        int e = 0;
        while (e < MAX_CHILD && root->child(e) == nullptr)
            e++;
        root = root->child(e)->combine(root, parent);
    }
    return root;
}

void RadixTree::print_tree(Node *root, int level)
{
    if (root == nullptr)
        return;
    static const wchar_t blank = L'\u252C', tri = L'\u251C', h_bar = L'\u2500', di = L'\u2514', v_bar = L'\u2502';
    static wstring prefix;

    // print root first
    string val = root->value();
    if (root->isdatanode())
        transform(val.begin(), val.end(), val.begin(), ::toupper);
    if (val.empty())
        wcout << blank << endl;
    else
        wcout << wstring(val.begin(), val.end()) << endl;

    int cc = root->child_count();
    for (int i = 0; i < MAX_CHILD; i++)
    {
        Node *child = root->child(i);
        if (child == nullptr)
            continue;
        cc--;
        wcout << prefix;
        wcout << (cc ? tri : di);
        wcout << h_bar << h_bar << h_bar;
        prefix.push_back(cc ? v_bar : ' ');
        prefix.append(L"   ");
        print_tree(child, level + 1);
        prefix.resize(prefix.size() - 4);
    }
}

void RadixTree::display()
{
    _setmode(_fileno(stdout), 0x00020000); // unicode mode
    print_tree(_root, 0);
    _setmode(_fileno(stdout), 0x00004000); // ascii mode
}

void RadixTree::get_entries(Node *root, string value, vector<string> &entries)
{
    if (root == nullptr || entries.size() == SUGGESTION_LIMIT)
        return;
    if (root->isdatanode() && entries.size() < SUGGESTION_LIMIT)
        entries.push_back(value);
    for (int i = 0; i < MAX_CHILD; i++)
    {
        auto child = root->child(i);
        if (child == nullptr)
            continue;

        get_entries(child, value + child->value(), entries);
    }
}

void RadixTree::autocomplete(Node *root, int index = 0)
{
    static char c;
    static string buffer;
    do
        c = getch();
    while (!isprint(c) && c != '\r' && (c != '\b' || buffer.empty()));
    if (c == '\r')
    {
        cout << endl;
        return;
    }

    if (c == '\b')
        return;

    buffer.push_back(c);
    do
    {
        Node *child = root;
        system("cls");
        cout << buffer;
        if (root != nullptr)
        {
            string val = root->value();
            if (index == val.size())
            {
                child = root->child(buffer.back() - 'a');
                index = 0;
            }
            if (child != nullptr)
            {
                val = child->value();
                if (val[index] == buffer.back())
                {
                    vector<string> entries;
                    get_entries(child, buffer + val.substr(index + 1), entries);
                    for (auto &entry : entries)
                    {
                        cout << endl
                             << entry;
                    }
                }
            }
        }

        autocomplete(child, index + 1);
    } while (c == '\0');
    if (c == '\b')
        c = '\0';
    buffer.pop_back();
    if (c == '\0' && buffer.empty())
    {
        system("cls");
        autocomplete(root);
    }
}

void menu()
{
    system("cls");
    cout << "1. Insert words" << endl;
    cout << "2. Remove words" << endl;
    cout << "3. Search a word" << endl;
    cout << "4. Display the tree" << endl;
    cout << "5. Auto-complete suggestion" << endl;
    cout << "0. Exit" << endl;
}

void main_menu()
{
    menu();
    int choice;
    cin >> choice;
    while (choice != 0)
    {
        system("cls");
        if (choice == 1)
        {
            int n;
            cout << "Input the number of words you want to insert: ";
            cin >> n;
            cout << "Input the words (consist of lowercase latin letters only):" << endl;
            for (int i = 0; i < n; i++)
            {
                string word;
                cin >> word;
                tree.insert(word);
            }
        }
        else if (choice == 2)
        {
            int n;
            cout << "Input the number of words you want to remove: ";
            cin >> n;
            cout << "Input the words (consist of lowercase latin letters only):" << endl;
            for (int i = 0; i < n; i++)
            {
                string word;
                cin >> word;
                if (tree.search(word))
                {
                    tree.remove(word);
                    cout << "Successfully removed!" << endl;
                }
                else
                    cout << "The word you provided doesn't exist!" << endl;
            }
        }
        else if (choice == 3)
        {
            string word;
            cout << "Input a word: ";
            cin >> word;
            cout << (tree.search(word) ? "Word exists!" : "Word doesn't exist!") << endl;
        }
        else if (choice == 4)
        {
            tree.display();
        }
        else if (choice == 5)
        {
            tree.autocomplete(tree.root());
        }
        else if (choice == 0)
            break;
        system("pause");
        menu();
        cin >> choice;
    }
}

int main()
{
    main_menu();
}