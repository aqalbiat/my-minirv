#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

pair < map <string, bool>, map <string, string> > parse_arguments(int arg_cnt, char **arg_val) {
    map <string, bool> exists;
    map <string, string> values;
    for (int i = 1; i < arg_cnt; i++) {
        string curr;
        for (int j = 0; arg_val[i][j] != '\0'; j++) {
            curr.push_back(arg_val[i][j]);
        }
        string cut_pref;
        if (curr.size() > 2 && curr.substr(0, 2) == "--") {
            cut_pref = curr.substr(2, curr.size() - 2);
        } else if (curr.size() > 1 && curr.front() == '-') {
            cut_pref = curr.substr(1, curr.size() - 1);
        } else {
            cut_pref = curr;
        }
        bool is_eq = false;
        string arg_name, arg_val;
        for (size_t it = 0; it < cut_pref.size(); it++) {
            if (cut_pref[it] == '=') {
                if (it == 0) {
                    cout << "No argument name in the assigned expression: ";
                    cout << cut_pref << endl;
                    exit(-1);
                }
                is_eq = true;
                arg_name = cut_pref.substr(0, it);
                arg_val = cut_pref.substr(it + 1, cut_pref.size() - it - 1);
                break;
            }
        }
        if (!is_eq) {
            exists[cut_pref] = true;
            values[cut_pref] = "?";
            continue;
        }
        exists[arg_name] = true;
        values[arg_name] = arg_val;
    }
    return make_pair(exists, values);
}
