#include <iostream>
#include <vector>
using namespace std;
class Car {
public:
    string Model;
    int Year , Mileage;
    Car (){
        Model = " ";
        Year = 0;
        Mileage = 0;
    }
    Car(string x,int y,int z){
        Model = x;
        Year = y;
        Mileage = z;
    }
    void set_info(string model, int year , int mileage) {
        Model = model;
        Year = year;
        Mileage = mileage;
    }

    string get_info() const {
        return "Mileage: " + to_string(Mileage) + ", Year: " + to_string(Year) + ", Model: " + Model;
    }

    void print() {
        cout << "Car Info:\n"
             << "Mileage: " << Mileage << "\n"
             << "Year: " << Year << "\n"
             << "Model: " << Model << endl;
    }
};
class Maintenance_Record {
public:
    int Cost;
    string Description, Date, Next_maintenance;

    Maintenance_Record() {
        Cost = 0;
        Date = " ";
        Description = " ";
        Next_maintenance = " ";
    }

    Maintenance_Record(string date, string description, string next_maintenance, int cost) {
        Date = date;
        Description = description;
        Next_maintenance = next_maintenance;
        Cost = cost;
    }

    void set_record(string date, string description, string next_maintenance, int cost) {
        Date = date;
        Description = description;
        Next_maintenance = next_maintenance;
        Cost = cost;
    }

    string get_record() {
        return "Date: " + Date + ", Description: " + Description + ", Next Maintenance: " + Next_maintenance + ", Cost: $" + to_string(Cost);
    }

    void print() {
        cout << "Maintenance Record:\n"
             << "Date: " << Date << "\n"
             << "Description: " << Description << "\n"
             << "Next Maintenance: " << Next_maintenance << "\n"
             << "Cost: $" << Cost << endl;
    }
};
class Mechanic {
public:
    string Name, Expertise, Contact_info;

    Mechanic() {
        Name = " ";
        Expertise = " ";
        Contact_info = " ";
    }

    Mechanic(string name, string expertise, string contact_info) {
        Name = name;
        Expertise = expertise;
        Contact_info = contact_info;
    }

    void perform_maintenance() {
        cout << "Performing maintenance..." << endl;
    }
};

class ServiceCenter : public Mechanic {
public:
    string CenterName, Location;
    ServiceCenter(string name, string expertise, string contact_info, string center_name, string location)
            : Mechanic(name, expertise, contact_info), CenterName(center_name), Location(location) {}
    void display_center_info() {
        cout << "Service Center Information:\n"
             << "Center Name: " << CenterName << "\n"
             << "Location: " << Location << "\n"
             << "Mechanic Name: " << Name << "\n"
             << "Expertise: " << Expertise << "\n"
             << "Contact Info: " << Contact_info << endl;
    }
};
class Owner {
public:
    string Name, Address;
    vector<Car> cars;

    Owner(string name, string address)
            : Name(name), Address(address) {}

    void display_owner_info() const {
        cout << "Owner Information:\n"
             << "Name: " << Name << "\n"
             << "Address: " << Address << endl;
    }

    void add_car(const Car& new_car) {
        cars.push_back(new_car);
        cout << "Car added successfully!" << endl;
    }

    void get_cars() const {
        cout << "Cars owned by " << Name << ":\n";
        for (const auto& car : cars) {
            cout << car.get_info() << endl;
        }
    }

    void contact_owner() const {
        cout << "Contact " << Name << " at " << Address << " for any inquiries." << endl;
    }
};
class Damaged_Part {
private:
    string partName;
    double repairCost;

public:

    Damaged_Part (){
        partName = " ";
        repairCost = 0.0;
    }
    Damaged_Part (string name , double cost){
        partName = name;
        repairCost = cost;
    }


    void set_part(string name, double cost) {
        partName = name;
        repairCost = cost;
    }

    string get_part_name() const {
        return partName;
    }

    double get_repair_cost() const {
        return repairCost;
    }


    void display_info() const {
        cout << "Damaged Part: " << partName << "\nRepair Cost: $" << repairCost << endl;
    }
};
class Warranty {
private:
    string provider;
    string startDate;
    string endDate;
    string coveredPart;

public:

    Warranty(){
        provider = " ";
        startDate = " ";
        endDate = " ";
        coveredPart = " ";
    }
    Warranty(string prov, string start, string end, string part){
        provider = prov;
        startDate = start;
        endDate = end;
        coveredPart = part;
    }


    void set_warranty(string prov, string start, string end, string part) {
        provider = prov;
        startDate = start;
        endDate = end;
        coveredPart = part;
    }

    string get_provider() const {
        return provider;
    }

    string get_start_date() const {
        return startDate;
    }

    string get_end_date() const {
        return endDate;
    }

    string get_covered_part() const {
        return coveredPart;
    }
    bool is_part_covered(const string& part) const {
        return part == coveredPart;
    }
    void display_info() const {
        cout << "Warranty Provider: " << provider << "\n"
             << "Start Date: " << startDate << "\n"
             << "End Date: " << endDate << "\n"
             << "Covered Part: " << coveredPart << endl;
    }
};

class Insurance_Policy {
private:
    string policy_number;
    string provider;
    string start_date;
    string end_date;
    string coverage_details;

public:

    Insurance_Policy() {
        policy_number = " ";
        provider = " ";
        start_date = " ";
        end_date = " ";
        coverage_details = " ";
    }
    Insurance_Policy(string policyNum, string prov, string start, string end, string coverage) {
        policy_number = policyNum;
        provider = prov;
        start_date = start;
        end_date = end;
        coverage_details = coverage;
    }

    void set_policy(string policyNum, string prov, string start, string end, string coverage) {
        policy_number = policyNum;
        provider = prov;
        start_date = start;
        end_date = end;
        coverage_details = coverage;
    }

    string get_policy_number() const {
        return policy_number;
    }

    string get_provider() const {
        return provider;
    }

    string get_start_date() const {
        return start_date;
    }

    string get_end_date() const {
        return end_date;
    }

    string get_coverage_details() const {
        return coverage_details;
    }

    bool is_covered(const string& part) const {
        return coverage_details.find(part) != string::npos;
    }

    void display_info() const {
        cout << "Policy Number: " << policy_number << "\n"
             << "Provider: " << provider << "\n"
             << "Start Date: " << start_date << "\n"
             << "End Date: " << end_date << "\n"
             << "Coverage Details: " << coverage_details << endl;
    }
};
class Bill : public Damaged_Part, public Insurance_Policy {
private:
    int bill_number;
    string date;
    double amount;
    vector<Damaged_Part> items;
    double total_cost;

public:

    Bill() {
        bill_number = 0;
        date = " ";
        amount = 0.0;
        total_cost = 0.0;

    }
    Bill(int number, string bill_date, double bill_amount, const vector<Damaged_Part>& parts,
         string policyNum, string prov, string start, string end, string coverage)
            : bill_number(number), date(bill_date), amount(bill_amount), items(parts),
              Insurance_Policy(policyNum, prov, start, end, coverage) {
        calculate_total_cost();
    }

    void calculate_total_cost() {
        total_cost = 0.0;
        for (const auto& item : items) {
            total_cost += item.get_repair_cost();
        }
    }
    void set_bill(int number, string bill_date, double bill_amount, const vector<Damaged_Part>& parts,
                  string policyNum, string prov, string start, string end, string coverage) {
        bill_number = number;
        date = bill_date;
        amount = bill_amount;
        items = parts;
        set_policy(policyNum, prov, start, end, coverage);
        calculate_total_cost();
    }

    double get_total_cost() const {
        return total_cost;
    }

    bool is_covered_by_insurance() const {
        for (const auto& item : items) {
            if (!is_covered(item.get_part_name())) {
                return false;
            }
        }
        return true;
    }

    void display_info() const {
        cout << "Bill Number: " << bill_number << "\n"
             << "Date: " << date << "\n"
             << "Amount: $" << amount << "\n"
             << "Items: " << endl;
        for (const auto& item : items) {
            item.display_info();
        }
        cout << "Total Cost: $" << total_cost << endl;
        cout << "Insurance Policy Info: " << endl;
        Insurance_Policy::display_info();
        cout << "Insurance covers all items: " << (is_covered_by_insurance() ? "Yes" : "No") << endl;
    }
};
class Customer_Feedback {
private:
    string customer_name;
    string feedback_message;
    int rating;
    string date;

public:
    Customer_Feedback() {
        customer_name = "";
        feedback_message = "";
        rating = 0;
        date = "";
    }

    Customer_Feedback(string name, string feedback, int rate, string feedback_date) {
        customer_name = name;
        feedback_message = feedback;
        rating = rate;
        date = feedback_date;
    }

    void set_feedback(string name, string feedback, int rate, string feedback_date) {
        customer_name = name;
        feedback_message = feedback;
        rating = rate;
        date = feedback_date;
    }

    string get_customer_name() const {
        return customer_name;
    }

    string get_feedback_message() const {
        return feedback_message;
    }

    int get_rating() const {
        return rating;
    }

    string get_date() const {
        return date;
    }
    void display_feedback() const {
        cout << "Customer Name: " << customer_name << "\n"
             << "Feedback: " << feedback_message << "\n"
             << "Rating: " << rating << "\n"
             << "Date: " << date << endl;
    }
};
class Node {
public:
    int value;
    Node* next;

    Node(int x) : value(x), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool empty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* new_node = new Node(x);
        if (empty()) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (!empty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    void print() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool search(int x) {
        Node* current = front;
        while (current != nullptr) {
            if (current->value == x) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class ServiceRequest {
private:
    Queue requests;

public:
    void add_request(const string& customer_name, bool is_fast_order) {
        int order_type = is_fast_order ? 1 : 0;
        requests.enqueue(order_type);
        cout << "Service request added for " << customer_name << ". Type: " << (is_fast_order ? "Fast" : "Normal") << " order." << endl;
    }

    void process_request() {
        if (!requests.empty()) {
            requests.dequeue();
            cout << "Finished service request removed." << endl;
        } else {
            cout << "No requests to process." << endl;
        }
    }

    void display_requests() {
        cout << "Current Service Requests:" << endl;
        requests.print();
    }
};



int main() {

    Car car1("Toyota", 2022, 5000);
    Car car2("Honda", 2020, 8000);

    Maintenance_Record record1("2024-07-12", "Oil Change", "2025-01-12", 50);
    Maintenance_Record record2("2024-06-30", "Brake Inspection", "2024-12-30", 80);

    Mechanic mechanic1("Bebo", "Engine Specialist", "123-456-7890");
    ServiceCenter serviceCenter1("Bassam", "Engine Specialist", "123-456-7890", "Service Center A", "City A");

    Owner owner1("Sara", "23 Al-Shorouk City");
    owner1.add_car(car1);
    owner1.add_car(car2);

    Damaged_Part part1("Brake Pad", 120.0);
    Damaged_Part part2("Headlight", 80.0);

    Warranty warranty1("Ghabbour Auto (GB Auto)", "2024-01-01", "2026-01-01", "Engine");
    Warranty warranty2("Ghabbour Auto (GB Auto)", "2023-06-01", "2025-06-01", "Transmission");

    Insurance_Policy insurance1("AL7890123", "Misr Insurance Company (MIC)", "2023-01-01", "2025-01-01", "Coverage: Engine, Transmission");
    Insurance_Policy insurance2("SF1234567", "Misr Insurance Company (MIC)", "2024-01-01", "2026-01-01", "Coverage: Body, Interior");

    vector<Damaged_Part> parts = {part1, part2};
    Bill bill1(1001, "2024-07-12", 200.0, parts, "AL7890123", "Misr Insurance Company (MIC)", "2023-01-01", "2025-01-01", "Coverage: Engine, Transmission");

    Customer_Feedback feedback1("Ahmed", "Great service!", 7, "2024-07-12");
    Customer_Feedback feedback2("Sayed", "Satisfied with the repairs.", 9, "2024-07-11");

    car1.print();
    cout << "==================" << endl;

    record1.print();
    cout << "==================" << endl;

    mechanic1.perform_maintenance();
    cout << "==================" << endl;

    serviceCenter1.display_center_info();
    cout << "==================" << endl;

    owner1.display_owner_info();
    cout << "==================" << endl;

    part1.display_info();
    cout << "==================" << endl;

    warranty1.display_info();
    cout << "==================" << endl;

    insurance1.display_info();
    cout << "==================" << endl;

    bill1.display_info();
    cout << "==================" << endl;

    feedback1.display_feedback();
    cout << "==================" << endl;

    return 0;
}