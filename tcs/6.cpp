#include <bits/stdc++.h>
using namespace std;

bool isBullet(const string &w) {
    if (w == "*" || w == "-") return true;
    if (w.size() >= 2 && isdigit(w[0]) && (w[1] == '.' || w[1] == ')')) return true;
    return false;
}

bool isEmailOrUrl(const string &w) {
    return (w.find('@') != string::npos ||
            w.rfind("http://", 0) == 0 ||
            w.rfind("https://", 0) == 0);
}

string trimSpaces(const string &s) {
    string out;
    bool space = false;
    for (char c : s) {
        if (isspace(c)) {
            if (!out.empty() && !space) {
                out += ' ';
                space = true;
            }
        } else {
            out += c;
            space = false;
        }
    }
    if (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    vector<string> raw(N);
    for (int i = 0; i < N; i++) getline(cin, raw[i]);

    string cmd;
    getline(cin, cmd);

    int defaultW = 75;
    int evenW = -1, oddW = -1;

    stringstream ss(cmd);
    string token;
    while (ss >> token) {
        if (token == "-w") {
            string val; ss >> val;
            if (isdigit(val[0])) defaultW = stoi(val);
        } else if (token == "-w-e") {
            ss >> evenW;
        } else if (token == "-w-o") {
            ss >> oddW;
        }
    }

    if (evenW == -1) evenW = defaultW;
    if (oddW == -1) oddW = defaultW;


    vector<vector<string>> paragraphs;
    vector<string> current;
    for (string &line : raw) {
        string clean = trimSpaces(line);
        if (clean.empty()) {
            if (!current.empty()) {
                paragraphs.push_back(current);
                current.clear();
            }
        } else {
            current.push_back(clean);
        }
    }
    if (!current.empty()) paragraphs.push_back(current);

    int lineIdx = 0;


    for (int p = 0; p < (int)paragraphs.size(); p++) {
        vector<string> output;
        vector<string> words;

        for (string &line : paragraphs[p]) {
            stringstream s2(line);
            string w;
            while (s2 >> w) words.push_back(w);
        }

        string curr = "";
        for (string &word : words) {
            int width = (lineIdx % 2 == 0 ? evenW : oddW);

            if (isBullet(word)) {
                if (!curr.empty()) {
                    output.push_back(trimSpaces(curr));
                    curr = "";
                    lineIdx++;
                }
                curr = word + " ";
                continue;
            }

            if (isEmailOrUrl(word)) {
                if (curr.empty()) {
                    output.push_back(word);
                    lineIdx++;
                } else {
                    if ((int)(curr.size() + 1 + word.size()) <= width) {
                        curr += " " + word;
                    } else {
                        output.push_back(trimSpaces(curr));
                        lineIdx++;
                        curr = word;
                    }
                }
                continue;
            }

            if (curr.empty()) {
                curr = word;
            } else if ((int)(curr.size() + 1 + word.size()) <= width) {
                curr += " " + word;
            } else {
                output.push_back(trimSpaces(curr));
                lineIdx++;
                curr = word;
            }
        }

        if (!curr.empty()) {
            output.push_back(trimSpaces(curr));
            lineIdx++;
        }

  
        for (int i = 0; i < (int)output.size(); i++) {
            cout << output[i] << "\n";
        }

  
        if (p != (int)paragraphs.size() - 1)
            cout << "\n";
    }

    return 0;
}
