#include<bits/stdc++.h>
using namespace std;

class PatientNode {
public:
    string patname;
    int id;
    PatientNode *left;
    PatientNode *right;
    bool rightthread;

    PatientNode(string name, int idno) {
        patname = name;
        id = idno;
        left = nullptr;
        right = nullptr;
        rightthread = false;
    }
};

class Department {
public:
    string Deptname;
    Department *left;
    Department *right;
    Department *leftsubdept;
    Department *rightsubdept;
    PatientNode *patientroot;

    Department(string name) {
        Deptname = name;
        left = nullptr;
        right = nullptr;
        patientroot = nullptr;
        leftsubdept = nullptr;
        rightsubdept = nullptr;
    }

    void Addpatient(string name, int id) {
        patientroot = Addpatient(patientroot, name, id);
    }

    PatientNode* Addpatient(PatientNode* root, string name, int id) {
        PatientNode* newNode = new PatientNode(name, id);
        if (root == nullptr) {
            return newNode;
        }
        PatientNode* parent = nullptr;
        PatientNode* current = root;
        while (current != nullptr) {
            parent = current;
            if (id < current->id) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    newNode->right = current;
                    newNode->rightthread = true;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->rightthread) {
                    newNode->right = current->right;
                    newNode->rightthread = true;
                    current->right = newNode;
                    current->rightthread = false;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
        return root;
    }

    void DischargePatient(int id) {
        cout<<"Discharged patient "<<id<<endl;
        patientroot = DischargePatient(patientroot, id);
    }

    PatientNode* DischargePatient(PatientNode* root, int id) {
        if (root == nullptr) return root;
        if (id < root->id) {
            root->left = DischargePatient(root->left, id);
        } else if (id > root->id) {
            root->right = DischargePatient(root->right, id);
        } else {
            if (root->left == nullptr) {
                PatientNode* temp = root->right;
                if (root->rightthread) {
                    temp = nullptr;
                }
                delete root;
                return temp;
            } else if (root->right == nullptr || root->rightthread) {
                PatientNode* temp = root->left;
                delete root;
                return temp;
            }
            PatientNode* temp = minValueNode(root->right);
            root->id = temp->id;
            root->patname = temp->patname;
            root->right = DischargePatient(root->right, temp->id);
        }
        cout << "The patient with ID: " << id << " is discharged from the hospital." << endl;
        return root;
    }

    PatientNode* minValueNode(PatientNode* node) {
        PatientNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void Displaypatient() {
        Displaypatient(patientroot);
    }

    void Displaypatient(PatientNode* root) {
        if (root == nullptr){
        return;
        }

        PatientNode* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }

        while (current != nullptr) {
            cout << "Patient Name: " << current->patname << ", Patient Id: " << current->id << endl;
            if (current->rightthread) {
                current = current->right;
            } else {
                current = current->right;
                while (current != nullptr && current->left != nullptr) {
                    current = current->left;
                }
            }
        }
    }

    void AddSubdepartment(string subdeptname) {
        if (leftsubdept == nullptr) {
            leftsubdept = new Department(subdeptname);
        } else {
            Department *temp = leftsubdept;
            while (temp->rightsubdept != nullptr) {
                temp = temp->rightsubdept;
            }
            temp->rightsubdept = new Department(subdeptname);
        }
    }

    void displaysubdepartments() {
        Department *temp = leftsubdept;
        while (temp != nullptr) {
            cout << "SUB_DEPARTMENT: " << temp->Deptname << endl;
            temp = temp->rightsubdept;
        }
    }
};

class Hospital {
    Department *root;

public:
    Hospital() {
        root = nullptr;
    }

    Department* getroot() {
        return root;
    }

    void addDepartment(string name) {
        root = addDepartment(root, name);
    }

    Department* addDepartment(Department* root, string name) {
        if (root == nullptr) {
            return new Department(name);
        }
        if (name < root->Deptname) {
            root->left = addDepartment(root->left, name);
        } else if (name > root->Deptname) {
            root->right = addDepartment(root->right, name);
        } else {
            cout << "Department names can't be the same" << endl;
        }
        return root;
    }

    void DisplayDepartments() {
        cout << "The Departments In The Hospital Are:" << endl;
        DisplayDepartments(root);
    }

    void DisplayDepartments(Department* root) {
        if (root == nullptr) return;
        DisplayDepartments(root->left);
        cout << "Department: " << root->Deptname << endl;
        DisplayDepartments(root->right);
    }

    Department* findDepartment(string name) {
        return findDepartment(root, name);
    }

    Department* findDepartment(Department* root, string name) {
        if (root == nullptr) return nullptr;
        if (root->Deptname == name) {
            return root;
        } else if (root->Deptname > name) {
            return findDepartment(root->left, name);
        } else {
            return findDepartment(root->right, name);
        }
    }
};



int main() {
    Hospital hos;
    bool running = true;

    while (running) {
        cout << "1. Add Department\n";
        cout << "2. Display All Departments\n";
        cout << "3. Add Patient to a Department\n";
        cout << "4. Discharge Patient from a Department\n";
        cout << "5. Display Patients in a Department\n";
        cout << "6. Add Subdepartment\n";
        cout << "7. Display Subdepartments\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string deptName;
                cout << "Enter department name: ";
                cin >> deptName;
                hos.addDepartment(deptName);
                cout << "Department " << deptName << " added successfully!\n";
                break;
            }

            case 2: {
                hos.DisplayDepartments();
                break;
            }

            case 3: {
                string deptName, patientName;
                int patientId;
                cout << "Enter department name: ";
                cin >> deptName;
                Department* dept = hos.findDepartment(deptName);
                if (dept) {
                    cout << "Enter patient name: ";
                    cin >> patientName;
                    cout << "Enter patient ID: ";
                    cin >> patientId;
                    dept->Addpatient(patientName, patientId);
                    cout << "Patient " << patientName << " added to " << deptName << " department.\n";
                } else {
                    cout << "Department not found!\n";
                }
                break;
            }

            case 4: {
                string deptName;
                int patientId;
                cout << "Enter department name: ";
                cin >> deptName;
                Department* dept = hos.findDepartment(deptName);
                if (dept) {
                    cout << "Enter patient ID to discharge: ";
                    cin >> patientId;
                    dept->DischargePatient(patientId);
                } else {
                    cout << "Department not found!\n";
                }
                break;
            }

            case 5: {
                string deptName;
                cout << "Enter department name: ";
                cin >> deptName;
                Department* dept = hos.findDepartment(deptName);
                if (dept) {
                    cout << "Displaying patients in " << deptName << " department:\n";
                    dept->Displaypatient();
                } else {
                    cout << "Department not found!\n";
                }
                break;
            }

            case 6: {
                // Add subdepartment
                string deptName, subDeptName;
                cout << "Enter department name: ";
                cin >> deptName;
                Department* dept = hos.findDepartment(deptName);
                if (dept) {
                    cout << "Enter subdepartment name: ";
                    cin >> subDeptName;
                    dept->AddSubdepartment(subDeptName);
                    cout << "Subdepartment " << subDeptName << " added to " << deptName << " department.\n";
                } else {
                    cout << "Department not found!\n";
                }
                break;
            }

            case 7: {
                string deptName;
                cout << "Enter department name: ";
                cin >> deptName;
                Department* dept = hos.findDepartment(deptName);
                if (dept) {
                    dept->displaysubdepartments();
                } else {
                    cout << "Department not found!\n";
                }
                break;
            }

            case 8: {
                cout << "Exiting Hospital Management System. Stay Safe!\n";
                running = false;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}

