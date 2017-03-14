#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class K, class V> class KeyValuePair{
    private:
        K key;
        V value;
    public:
        KeyValuePair(K _key, V _value) : key(_key), value(_value){}
        V GetValue(){
            return value;
        }
        K GetKey(){
            return key;
        }
};

template<class K, class V> class Dictionary{
    private:
        vector<KeyValuePair<K, V> > elements;
    public:
        V GetValue(K key){
            for(int e = 0; e < elements.size(); e++){
                if(elements[e].GetKey() == key) return elements[e].GetValue();
            }
            return NULL;
        }
        K GetKey(V value){
            for(int e = 0; e < elements.size(); e++){
                if(elements[e].GetValue() == value) return elements[e].GetKey();
            }
            return NULL;
        }
        void Add(K key, V value){
            elements.push_back(KeyValuePair<K,V>(key, value));
        }
        V operator[](K key){
            return this->GetValue(key);
        }
};

int main()
{
    Dictionary<int, string> dict;
    
    dict.Add(1, "a");
    cout << dict[4] << endl;
    
   return 0;
}
