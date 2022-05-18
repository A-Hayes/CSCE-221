#include "my_map.h"
#include "text_freq.h"
#include <iostream>
using namespace std;
int main()
{
    my_map<string, int> m;
    m["c"] = 10;
    m["f"] = 3;
    m["b"] = 4;
    m["a"] = 5;
    m["d"] = 15;
    m["e"] = 15;
    m["f"] = 15;

    cout << endl << m << endl;

    auto curr = m.begin();

    while(curr != m.end())
    {
        cout << *curr << endl;
        curr++;
    }

    cout << endl << "File Tests: " << endl;

    string inText = read_file("test_text1.txt");
    my_map<string, double> docMap = create_freq_map(inText);
    vector<key_value<string,double>> mapVec = vectorize_map(docMap);
    cout << "mapVec size: " << mapVec.size() << endl;
    vector<string> stop_words = {"a", "ac", "sit", "et"};
    remove_stop_words(mapVec, stop_words);
    cout << "mapVec size after filtering words: " << mapVec.size() << endl;
    print_top_20_freqs(mapVec, cout);
}
