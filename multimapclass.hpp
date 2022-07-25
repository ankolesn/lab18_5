//
// Created by ankolesn on 24.07.22.
//

#ifndef LAB18_5_MULTIMAPCLASS_HPP
#define LAB18_5_MULTIMAPCLASS_HPP

#include <map>
#include <list>
#include <string>

template<typename Key, typename Value>
class Multimap_class {
private:
    std::map<Key, std::list<Value>> mp;

public:

    void insert(const Key &key, Value value);

    const std::list<int> &find(const Key &key);

    void erase(const Key &key);

    friend std::ostream &operator<<(std::ostream &out, const Multimap_class<Key, Value> &nt) {
        for (auto &i: nt.mp) {
            for (auto &j: i.second) {
                out << "Key: " << i.first << std::endl;
                out << "Value: " << j << std::endl;
            }
        }
        return out;
    }

};

template<typename Key, typename Value>
void Multimap_class<Key, Value>::insert(const Key &key, Value value) {
    auto it = mp.find(key);
    if (it != mp.end()) {
        mp[key].push_back(value);
    }
    else{
        mp.insert(std::pair(key, std::list<Value>()));
        mp[key].push_back(value);
    }
}


template<typename Key, typename Value>
const std::list<int> &Multimap_class<Key, Value>::find(const Key &key) {
    auto it = mp.find(key);
    if(it != mp.end())
        return it->second;
}

template<typename Key, typename Value>
void Multimap_class<Key, Value>::erase(const Key &key) {
    auto it = mp.find(key);
    if(it != mp.end()){
        mp.erase(it);
    }
}


#endif //LAB18_5_MULTIMAPCLASS_HPP
