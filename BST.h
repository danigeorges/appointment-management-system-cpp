#include<iostream>
using namespace std;


class Appointment
{
public:
    string patientName;
    int priority;
    string department;

    Appointment()
    {
        patientName = "";
        priority = 0;
        department = "";
    }

    Appointment(string name, int Priority, string dept)
    {
        patientName = name;
        priority = Priority;
        department = dept;
    }
};

class Node
{
public:
    Appointment newappointement;
    Node* left;
    Node* right;

    Node(int value, string name, string dept)
    {
        newappointement.patientName = name;
        newappointement.department = dept;
        newappointement.priority = value;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node* root;
    Node* insert(Node* root, int value, string name, string dept)
    {
        if (root == nullptr)
        {
            Node* newnode = new Node(value, name, dept);
            root = newnode;
            return root;
        }
        if (value <= root->newappointement.priority)
            root->left = insert(root->left, value, name, dept);
        else 
            root->right = insert(root->right, value, name, dept);
        return root;
    }
    void displayinorder(Node* root)
    {
        if (root == nullptr)
            return;
        displayinorder(root->left);
        cout << "Patient Name : " << root->newappointement.patientName << endl;
        cout << "Priotity : " << root->newappointement.priority << endl;
        cout << "Departement : " << root->newappointement.department << endl;
        displayinorder(root->right);
    }
    void Search(Node* root, int Priority)
    {
        if (root == nullptr)
        {
            return ;
        }
        if (root->newappointement.priority == Priority)
        {
            cout << "Patient Name : " << root->newappointement.patientName << endl;
            cout << "Priotity : " << root->newappointement.priority << endl;
            cout << "Departement : " << root->newappointement.department << endl;
             Search(root->left, Priority);
             Search(root->right, Priority);
             return;
            
        }
        else if (root->newappointement.priority > Priority)
        {
            return Search(root->left, Priority);
        }
        else
        {
            return Search(root->right, Priority);
        }
    }
    Node* Delete(Node* root, int value)
    {
        if (root == nullptr)
            return nullptr;
         if (value < root->newappointement.priority)
            root->left = Delete(root->left, value);
        else if(value > root->newappointement.priority)
            root->right = Delete(root->right, value);
        else
        {
            if (root->left == nullptr && root->right==nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return Delete(temp,value);
            }
            else
            {
                Node* temp = root->right;
                while (temp->left != nullptr)
                    temp = temp->left;
                root->newappointement = temp->newappointement;
                root->right = Delete(root->right, temp->newappointement.priority);
                root->left = Delete(root->left, value);
            }
        }
        return root;
    }
    void displayMoreUrgent(Node* root, int value)
    {
        if (root==nullptr)
        {
            return;
        }
        displayMoreUrgent(root->left, value);
        if (root->newappointement.priority<=value)
        {
            cout << "Patient Name : " << root->newappointement.patientName << endl;
            cout << "Priotity : " << root->newappointement.priority << endl;
            cout << "Departement : " << root->newappointement.department << endl;
            
            displayMoreUrgent(root->right, value);
        }
        else
        {
            displayMoreUrgent(root->right, value);
        }
    }
    void displayLessUrgent(Node* root, int value)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->newappointement.priority >= value)
        {
            displayLessUrgent(root->left, value);
            cout << "Patient Name : " << root->newappointement.patientName << endl;
            cout << "Priotity : " << root->newappointement.priority << endl;
            cout << "Departement : " << root->newappointement.department << endl;
            displayLessUrgent(root->right, value);
        }
        else
        {
            displayLessUrgent(root->left, value);
        }
    }


public:

    BST()
    {
        root = nullptr;
    }
    void insert(Appointment newappointement)
    {
        root = insert(root, newappointement.priority, newappointement.patientName, newappointement.department);
    }
    void displayinorder()
    {
        displayinorder(root);
    }
    void Search(int Priority)
    {
        Search(root, Priority);
    }
    void Delete( int value)
    {
        root=Delete(root, value);
    }
    void displayMoreUrgent(int value)
    {
         displayMoreUrgent(root, value);
    }
    void displayLessUrgent(int value)
    {
        displayLessUrgent(root, value);
    }
};

