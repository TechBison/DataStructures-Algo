#include<bits/stdc++.h>

using namespace std;


template <typename K, typename V>

class hash_map
{
    private:

        static const int BUCKET_COUNT = 10;

        vector<list<pair<K,V>>> buckets;
        
        int getBucketIndex(const K  &key){
            return hash<K>{}(key) % BUCKET_COUNT;
        }

    public:
        hash_map(){
            buckets.resize(BUCKET_COUNT);
        };

        void insert (const K& key, const V& value){
            int idx = getBucketIndex(key);
            for(auto& pair : buckets[idx]){
                if(pair.first == key){
                    pair.second = value;
                    return ;
                }
            }
            buckets[idx].push_back(key,value);
        }

        bool isPresent(const K& key){
            auto idx = getBucketIndex(key);
            for(auto& pair : buckets[idx]){
                if(pair.first == key){
                    
                }
            }

        }

        ~hash_map();
};

