#include "text_freq.h"
#include "my_map.h"
#include "key_value.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

string read_file(string file_name)
{

    string fullText = "";
    string tempString;
    ifstream in(file_name);

    if(!in){
      cout << "cannot open file" << endl;
      return "";
    }

    while( getline( in, tempString ) ){
      fullText += tempString;
    }

    fullText = remove_punctuation(fullText);

    for(int i = 0; i < fullText.length(); ++i) {
      fullText[i] = tolower(fullText[i]);
    }

    in.close();

    return fullText;
}

string remove_punctuation(string& text)
{
    string result;
    std::remove_copy_if(text.begin(), text.end(),
    std::back_inserter(result), //Store output
    std::ptr_fun<int, int>(&std::ispunct));
    return result;
}

my_map<string, double> create_freq_map(const string& text)
{
    my_map<string,double> freq_map;
    int wordTotal = 0;

    istringstream words(text);
    string curWord = "";

    while( words >> curWord ){
      freq_map[curWord]++;
      wordTotal++;
    }

    for(auto i = freq_map.begin(); i != freq_map.end(); i++){
      (*i).value /= wordTotal;
    }

    return freq_map;
}

// Assuming that the sorted vector is by key, not by frequency value
vector<key_value<string,double>> vectorize_map(my_map<string, double>& freq_map)
{

    vector<key_value<string,double>> freq_vec;

    for(auto i = freq_map.begin(); i != freq_map.end(); i++){
      freq_vec.push_back(*i);
    }

    cout << endl;

    return freq_vec;

}

void remove_stop_words(vector<key_value<string,double>>& freq_vec, vector<string> stop_words)
{
   //FINISH THIS FUNCTION
   //this function should remove the elements contained in stop_words from freq_vec
   for(int j = 0; j < stop_words.size(); j++){
     for(auto i = freq_vec.begin(); i != freq_vec.end();){
       if( (*i).key == stop_words[j] ){
         i = freq_vec.erase(i);
       } else {
         i++;
       }
     }
   }



}

void print_top_20_freqs( vector<key_value<string,double>>& freq_vec, ostream& out)
{
    for(int i = 0; i < freq_vec.size(); i++){
      for(int j = i; j < freq_vec.size(); j++){
        if(freq_vec[i].value < freq_vec[j].value){
          swap(freq_vec[i], freq_vec[j]);
        }
      }
    }

    auto i = freq_vec.begin();
    int j = 0;
    while(i != freq_vec.end() && j < 20){
        out << *i << endl;
        i++;
        j++;
    }


    return;

}
