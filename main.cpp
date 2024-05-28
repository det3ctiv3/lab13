#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

// Function to display forward_list
void display_forward_list(const forward_list<double>& f_list) {
    for (auto it = f_list.begin(); it != f_list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    // Part 1: Basic vector operations and printing
    {
        vector<double> vec1;
        vec1.assign({23, 32, 4});
        for (auto i = vec1.begin(); i < vec1.end(); i++){
            cout << *i << endl;
        }
    }

    // Part 2: Reading input into a vector and printing front and back
    {
        vector<double> vec2;
        double input;
        cout << "Enter numbers for vec2 (non-number to stop):" << endl;
        while(cin >> input){
            vec2.push_back(input);
        }
        if (!vec2.empty()) {
            cout << "Front: " << vec2.front() << ", Back: " << vec2.back() << endl;
        }

    }

    // Part 3: Vector modification and printing
    {
        vector<double> vec3;
        vec3.assign({1, 2, 3, 4, 5, 6, 7, 8});
        if(!vec3.empty()){
            auto it = vec3.begin() + 3;
            vec3.erase(it);
            vec3.erase(vec3.begin() + 1, vec3.begin() + 2);
        }
        for (auto i : vec3){
            cout << i << " ";
        }
        cout << endl;
    }

    // Part 4: 2D vector input and printing
    {
        int num;
        cout << "Enter size for 2D vector:" << endl;
        cin >> num;
        vector<vector<double>> vec4(num, vector<double>(num, 0));

        cout << "Enter elements for 2D vector:" << endl;
        for (auto row = vec4.begin(); row != vec4.end(); row++)
            for (auto col = row->begin(); col != row->end(); col++){
                cin >> *col;
            }

        cout << "2D vector elements:" << endl;
        for (auto i : vec4){
            for (auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }

    }

    // Part 5: List splicing and printing
    {
        list<double> list1 = {3.3, 4.5, 6.7};
        list<double> list2 = {1, 2, 3};
        list<double> list3 = {8, 9.5, 10.3};

        list3.splice(list3.end(), list1);
        list3.splice(list3.end(), list2);
        for (auto i : list3){
            cout << i << " ";
        }
        cout << endl;
    }

    // Part 6: Forward list operations and printing
    {
        forward_list<double> f_list{1, 2, 3, 4, 5, 6};
        forward_list<double>::iterator it;
        it = f_list.begin();

        f_list.erase_after(it);
        display_forward_list(f_list);
        f_list.push_front(12);
        display_forward_list(f_list);
        f_list.emplace_front(10);
        display_forward_list(f_list);
        f_list.pop_front();
        display_forward_list(f_list);
        f_list.insert_after(it, 99);
        display_forward_list(f_list);
        f_list.emplace_after(it, 100);
        display_forward_list(f_list);
    }

    return 0;
}
