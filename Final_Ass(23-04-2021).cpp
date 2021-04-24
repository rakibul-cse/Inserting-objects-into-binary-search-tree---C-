#include <iostream>
using namespace std;

class EmployeeInfo{

    private:
        int empID;
        string empName;
        string department;
        string salary;
    public:
        EmployeeInfo();
        EmployeeInfo(int, string,string,string);
        int getEmpID();
        string getEmpName();
        string getDepartment();
        string getSalary();
        bool operator < (const EmployeeInfo &e){
            if (empID < e.empID){
                return true;
            }
            return false;
        }
        bool operator > (const EmployeeInfo &e){
            if (empID > e.empID){
                return true;
            }
            return false;
        }
        bool operator == (const EmployeeInfo &e){
            if (empID == e.empID){
                return true;
            }
            return false;
        }
};
    EmployeeInfo::EmployeeInfo(){
        empID = 0;
        empName = "";
        department="";
        salary="";
    }
    EmployeeInfo::EmployeeInfo(int ID, string name,string tDeptartment,string tSalary){
        empID = ID;
        empName = name;
        department=tDeptartment;
        salary=tSalary;
    }
    int EmployeeInfo::getEmpID(){
        return empID;
    }
    string EmployeeInfo::getEmpName(){
        return empName;
    }
    string EmployeeInfo::getDepartment(){
        return department;
    }
    string EmployeeInfo::getSalary(){
        return salary;
    }


class EmployeeTree{
private:
    struct TreeNode {
        EmployeeInfo value;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(EmployeeInfo, TreeNode *&);
    void displayInOrder(TreeNode *) const;

public:
    EmployeeTree(){
        root = NULL;
    }
    ~EmployeeTree(){
        destroySubTree(root);
    }
    void insertNode(EmployeeInfo);
    bool searchNode(int);
    void remove(EmployeeInfo);

    void displayInOrder() const{
        displayInOrder(root);
    }

};

    void EmployeeTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
        if (nodePtr == NULL){
            nodePtr = newNode;
        }
        else if (newNode->value < nodePtr->value){
            insert(nodePtr->left, newNode);
        }
        else{
            insert(nodePtr->right, newNode);
        }
    }
    void EmployeeTree::destroySubTree(TreeNode *nodePtr) {
        if (nodePtr){
            if (nodePtr->left){
                destroySubTree(nodePtr->left);
            }
            if (nodePtr->right){
                destroySubTree(nodePtr->right);
            }
            delete nodePtr;
        }
    }
    void EmployeeTree::displayInOrder(TreeNode *nodePtr) const {
        if (nodePtr){
            displayInOrder(nodePtr->left);
            cout << nodePtr->value.getEmpID() << " " << nodePtr->value.getEmpName()<< " " << nodePtr->value.getDepartment()<< " " << nodePtr->value.getSalary() << endl;
            displayInOrder(nodePtr->right);
        }
    }
    void EmployeeTree::insertNode(EmployeeInfo item) {
        TreeNode *newNode;
        newNode = new TreeNode;
        newNode->value = item;
        newNode->left = newNode->right = NULL;
        insert(root, newNode);
    }
    bool EmployeeTree::searchNode(int empID) {
        TreeNode *nodePtr = root;
        while (nodePtr){
            if (nodePtr->value.getEmpID() == empID){
                cout<<" Name of the employee is: "<<nodePtr->value.getEmpName()<< " " << nodePtr->value.getDepartment()<< " " << nodePtr->value.getSalary() <<endl;
                return true;
            }
            else if (empID < nodePtr->value.getEmpID()){
                nodePtr = nodePtr->left;
            }
            else{
                nodePtr = nodePtr->right;
            }
        }
        cout<<"Not found"<<endl;
        return false;
    }

void InsertEmployee(EmployeeTree tree);
void SearchEmployee(EmployeeTree tree);

void InsertEmployee(EmployeeTree tree)
{
    int ch;int empId;string empName;string department;string salary;
    cout<<" Enter Employee ID : ";
    cin>>empId;
    cout<<""<<endl;
    cout<<" Employee Name : ";
    cin>>empName;
    cout<<""<<endl;
    cout<<" Employee Department : ";
    cin>>department;
    cout<<""<<endl;
    cout<<" Employee Salary : ";
    cin>>salary;
    cout<<""<<endl;
    tree.insertNode(EmployeeInfo(empId, empName,department,salary));
     cout<<"\n\n ID  |  Name | Department | Salary"<<endl;
     cout<<"---------------------------------------"<<endl;
     tree.displayInOrder();
    cout<<"\n----------------------------"<<endl<<endl;
    cout<<" 1. Insert Employee Data"<<endl;
    cout<<" 2. Search Employee Data"<<endl<<endl;
    cout<<" 3. Exit"<<endl<<endl;
    cout<<" ENTER CHOICE : ";
    cin>>ch;
    if(ch==1)
    {
        InsertEmployee(tree);
    }
    else if(ch==2)
    {
       SearchEmployee(tree);
    }

}
void SearchEmployee(EmployeeTree tree)
{
    int ch;
     int id  = 0;
     cout<<" Enter the ID of the Employee to search: ";
     cin>>id;
     tree.searchNode(id);

    cout<<"\n----------------------------"<<endl<<endl;
    cout<<" 1. Insert Employee Data"<<endl;
    cout<<" 2. Search Employee Data"<<endl<<endl;
    cout<<" 3. Exit"<<endl<<endl;
    cout<<" ENTER CHOICE : ";
    cin>>ch;
    if(ch==1)
    {
        InsertEmployee(tree);
    }
    else if(ch==2)
    {
        SearchEmployee(tree);
    }
}

int main() {

    EmployeeTree tree;
    int ch;
    cout<<"----------------------------"<<endl<<endl;
    cout<<" 1. Insert Employee Data"<<endl;
    cout<<" 2. Search Employee Data"<<endl<<endl;
    cout<<" 3. Exit"<<endl<<endl;
    cout<<" ENTER CHOICE : ";
    cin>>ch;

    if(ch==1)
    {
        InsertEmployee(tree);
    }
    else if(ch==2)
    {
        SearchEmployee(tree);
    }
    return 0;
}
