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
    //Create new Dictionary object, with key type 'int' and value type 'string'
    Dictionary<int, string> dict;
    //Add a key value pair to the dictionary, where the key is 1, and the value is "a"
    dict.Add(1, "a");
    //Access the value in the dictionary associated with the key 1
    cout << dict[1] << endl;
    
   return 0;
}
