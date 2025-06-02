#include<bits/stdc++.h>
using namespace std;
/***************************************************
 * Custom Map Implementation in C++
 * This code implements a simple hash map using separate chaining
 * with linked lists to handle collisions.
 * It supports basic operations like insert, find, erase, and display.
 * Time Complexity:
 * - Insert: O(1) on average, O(n) in worst case (if all keys hash to the same bucket)
 * - Find: O(1) on average, O(n) in worst case
 * - Erase: O(1) on average, O(n) in worst case
 * Space Complexity: O(n) where n is the number of key-value pairs
 *******************************************************/

template <typename K, typename V> 

class cus_map{
    vector<list<pair<K,V>>> buckets; 
    static const int BUCKET_SIZE = 10; // Number of buckets
    
    int hashFunction(const K& key) const {
        return std::hash<K>()(key) % BUCKET_SIZE; // Simple hash function using std::hash
    }
    public:

    cus_map() {
        buckets.resize(BUCKET_SIZE);
    }

    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value; // Update value if key exists
                return;
            }
        }
        buckets[index].emplace_back(key, value); // Insert new key-value pair
    }

    void find(const K& key) const {
        int index = hashFunction(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                cout << "Key: " << key << ", Value: " << pair.second << endl;
                return;
            }
        }
        cout << "Key not found: " << key << endl;
    }

    void erase(const K& key) {
        int index = hashFunction(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it); // Remove the key-value pair
                return;
            }
        }
        cout << "Key not found: " << key << endl;
    }
   
    void display() const {
        for (int i = 0; i < BUCKET_SIZE; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : buckets[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            cout << endl;
        }
    }
    ~cus_map() {
        // Destructor to clean up if needed
    }
};

int main() {
    cus_map<string, int> myMap;

    myMap.insert("apple", 1);
    myMap.insert("banana", 2);
    myMap.insert("orange", 3);

    myMap.display();

    myMap.find("banana");
    myMap.find("grape");

    myMap.erase("apple");
    myMap.display();

    return 0;
}