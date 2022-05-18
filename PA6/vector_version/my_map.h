#ifndef MY_MAP_H
#define MY_MAP_H

#include "key_value.h"
#include <iterator>
#include <vector>
#include <iterator>
using namespace std;
template <typename T, typename E>
struct my_map
{
    class map_iter : public iterator<input_iterator_tag, key_value<T,E>>
    {
    public:
        int index;
        vector<key_value<T,E>>& vec;
        map_iter(int start, vector<key_value<T,E>>& vec_) :index(start), vec(vec_){}
        map_iter(const map_iter& iter) : index(iter.index), vec(iter.vec){}

        map_iter& operator++()
        {
            index++;
            return *this;
        }

        map_iter operator++(int) {map_iter tmp(*this); operator++(); return tmp;}
        bool operator==(const map_iter& rhs) const {return index == rhs.index;}
        bool operator!=(const map_iter& rhs) const {return index != rhs.index;}

        key_value<T,E>& operator*()
        {
          if(!this->vec.empty()){
            return vec[index];
			    }
          // return NULL;
        }
    };

    vector<key_value<T,E>> container;

    my_map() : container() { }
    my_map(const my_map<T, E>& other);
    my_map<T, E>& operator=( const my_map<T, E>& other );

    E& operator[](T search_key);
    E* search_for_key(T search_key);
    void insert_new_kvp(T search_key);
    map_iter begin()
    {
        return map_iter(0, container);
    }

    map_iter end()
    {
        return map_iter(container.size(), container);
    }
};

template <typename T, typename E>
ostream& operator<<(ostream& out, my_map<T, E> map)
{
    //FINISH THIS FUNCTION
    for(auto i = map.begin(); i != map.end(); ++i){
      out << *i << endl;
    }
    return out;
}

template <typename T, typename E>
my_map<T,E>::my_map(const my_map<T, E>& other)
    :   container(other.container)
{}

template <typename T, typename E>
my_map<T, E>& my_map<T,E>::operator=( const my_map<T, E>& other )
{
    container(other.container);
}

template <typename T, typename E>
E& my_map<T,E>::operator[](T search_key)
{
    for(auto i = begin(); i != end(); ++i){
      if( (*i).key == search_key){
        return (*i).value;
      }
    }

    insert_new_kvp(search_key);

    for(auto i = begin(); i != end(); ++i){
      if( (*i).key == search_key){
        return (*i).value;
      }
    }
}

// Attempt was made to have operator[] call search_for_key() twice instead of
// using the loops, but there were issues with pointer conversion not
// working and causing strange issues in unrelated places in code
template <typename T, typename E>
E* my_map<T,E>::search_for_key(T search_key)
{
    for(auto i = begin(); i != end(); ++i){
      if((*i).key == search_key){
        key_value<T,E> temp = *i;
        E foundVal = temp.value;
        return &foundVal;
      }
    }
    return E();
}

template <typename T, typename E>
void my_map<T,E>::insert_new_kvp(T search_key)
{
    //FINISH THIS FUNCTION
    //this should insert a new key_value object in sorted order by the key
    key_value<T,E> newVal( search_key, 0 );
    container.push_back( newVal );
}

#endif
