#include <bits/stdc++.h>

using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it) || *it == '.' || *it == '-')) ++it;
    return !s.empty() && it == s.end();
}


string fmax(string x, string y) {
    double x_ = atof (x.c_str());
    double y_ = atof(y.c_str());

    if (x_ > y_) {
        //cout<<"FMAX"<<std::to_string(x_);
        return std::to_string(x_);
    } else {
        //cout<<"FMAX"<<std::to_string(y_);
        return std::to_string(y_);
    }
}

string fmin(string x, string y) {
    double x_ = atof(x.c_str());
    double y_ = atof(y.c_str());
    if (x_ < y_) {
        return std::to_string(x_);
    } else {
        return std::to_string(y_);
    }
}


string fplus(string x, string y) {
    double x_ = atof(x.c_str());
    double y_ = atof(y.c_str());

    double  z_ = x_ + y_;

    return std::to_string(z_);

}

string fmult(string x, string y) {
    double x_ = atof(x.c_str());
    double y_ = atof(y.c_str());

    double  z_ = x_ * y_;

    return std::to_string(z_);

}



vector<string> fsplit(string input_) {

    vector<string> stokens;
    char * tokens;
    //printf ("Splitting string \"%s\" into tokens:\n",input_);
    tokens = strtok (strdup(input_.c_str())," \t");
    while (tokens != NULL)
    {
        //printf ("%s\n",tokens);
        stokens.push_back(std::string(tokens));
        tokens = strtok (NULL, " \t");

    }

    return stokens;
}

vector<string> eval_and (vector<string> tok){
    vector<string> res;
    for(int i = 0; i<tok.size();i++) {
        //cout<<"DEGB"<<tok[i]<<endl;
        if(std::string("&").compare(tok[i])==0) {
            string prev = res[res.size()-1];
            res.pop_back();

            string next = tok[i+1];
            if (!is_number(prev) || !is_number(next)) {
                throw std::invalid_argument("invalid_expr");
            }
            res.push_back(fmax(prev, next));
            i++;
        } else {
            //cout<<"PUS"<<tok[i];
            res.push_back(tok[i]);
        }
    }
    return res;
};

vector<string> eval_pipe (vector<string> tok){
    vector<string> res;
    for(int i = 0; i<tok.size();i++) {
        //cout<<"DEGB"<<tok[i]<<endl;
        if(std::string("|").compare(tok[i])==0) {
            string prev = res[res.size()-1];
            res.pop_back();

            string next = tok[i+1];
            if (!is_number(prev) || !is_number(next)) {
                throw std::invalid_argument("invalid_expr");
            }
            res.push_back(fmin(prev, next));
            i++;
        } else {
            //cout<<"PUS"<<tok[i];
            res.push_back(tok[i]);
        }
    }
    return res;
};


vector<string> eval_mult (vector<string> tok){
    vector<string> res;
    for(int i = 0; i<tok.size();i++) {
        //cout<<"DEGB"<<tok[i]<<endl;
        if(std::string("*").compare(tok[i])==0) {
            string prev = res[res.size()-1];
            res.pop_back();

            string next = tok[i+1];
            if (!is_number(prev) || !is_number(next)) {
                throw std::invalid_argument("invalid_expr");
            }
            res.push_back(fmult(prev, next));
            i++;
        } else {
            //cout<<"PUS"<<tok[i];
            res.push_back(tok[i]);
        }
    }
    return res;
};

vector<string> eval_plus (vector<string> tok){
    vector<string> res;
    for(int i = 0; i<tok.size();i++) {
        //cout<<"DEGB"<<tok[i]<<endl;
        if(std::string("+").compare(tok[i])==0) {
            string prev = res[res.size()-1];
            res.pop_back();

            string next = tok[i+1];
            if (!is_number(prev) || !is_number(next)) {
                throw std::invalid_argument("invalid_expr");
            }
            res.push_back(fplus(prev,next));
            i++;
        } else {
            //cout<<"PUS"<<tok[i];
            res.push_back(tok[i]);
        }
    }
    return res;
};


float calculator(string input_str) {
    //ofstream fout(getenv("OUTPUT_PATH"));

    float res;

    vector<string> stokens = fsplit(input_str);

    //cout<<"OP"<<endl;

    try {
        vector<string> resu = eval_plus(eval_mult(eval_pipe(eval_and(stokens))));
        return stof(resu[0]);
    } catch (exception) {
            return 0.0;
    }


}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));

    float res;
    //string input_str;
    //getline(cin, input_str);

    string input_str = "1 & 2 | 3 * 4 * 5 + -6  ";

    cout<<calculator(input_str);

    return 0;
}
