#include <bits/stdc++.h>
using namespace std;

int valueOf(const string &s) {
    if (s == "A") return 1;
    if (s == "J") return 11;
    if (s == "Q") return 12;
    if (s == "K") return 13;
    return stoi(s);
}

vector<pair<int,int>> readPlayerCards(int N) {
    vector<pair<int,int>> cards;
    for (int i = 0; i < N; ++i) {
        string c1s, c2s;
        int s1, s2;
        cin >> c1s >> s1 >> c2s >> s2;
        cards.emplace_back(valueOf(c1s), s1);
    }
    return cards;
}

vector<pair<int,int>> readOpponentCards(int N, const vector<pair<int,int>>& player1Cards) {
    vector<pair<int,int>> cards;
    cin.clear();
    cin.seekg(0);
    int skip; string dummy;
    cin >> skip;
    for (int i = 0; i < N; ++i) {
        string c1s, c2s;
        int s1, s2;
        cin >> c1s >> s1 >> c2s >> s2;
        cards.emplace_back(valueOf(c2s), s2);
    }
    return cards;
}

void rearrange(vector<pair<int,int>> &vec, vector<int> &order) {
    sort(vec.begin(), vec.end(), [&](const pair<int,int>& a, const pair<int,int>& b){
        if (a.first != b.first) return a.first < b.first;
        return order[a.second] > order[b.second];
    });
}

bool cardWins(pair<int,int> a, pair<int,int> b, vector<int> &order) {
    return a.first == b.first && order[a.second] < order[b.second];
}

string playGame(deque<pair<int,int>> &deck1, deque<pair<int,int>> &deck2, vector<int> &order) {
    vector<pair<int,int>> hand;
    int cur = 1;
    const long long MAX_STEPS = 5'000'000;
    long long steps = 0;
    while (true) {
        if (++steps > MAX_STEPS) return "TIE";
        if (cur == 1) {
            if (deck1.empty()) return deck2.empty() ? "TIE" : "LOSER";
            auto card = deck1.front(); deck1.pop_front();
            hand.push_back(card);
            bool won = hand.size() >= 2 && cardWins(hand.back(), hand[hand.size()-2], order);
            if (won) {
                vector<pair<int,int>> tmp = hand;
                rearrange(tmp, order);
                for (auto &c : tmp) deck1.push_back(c);
                hand.clear();
            } else cur = 2;
        } else {
            if (deck2.empty()) return deck1.empty() ? "TIE" : "WINNER";
            auto card = deck2.front(); deck2.pop_front();
            hand.push_back(card);
            bool won = hand.size() >= 2 && cardWins(hand.back(), hand[hand.size()-2], order);
            if (won) {
                vector<pair<int,int>> tmp = hand;
                rearrange(tmp, order);
                for (auto &c : tmp) deck2.push_back(c);
                hand.clear();
            } else cur = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int,int>> p1, p2;
    vector<tuple<string,int,string,int>> raw;
    for (int i = 0; i < N; ++i) {
        string c1s, c2s;
        int s1, s2;
        cin >> c1s >> s1 >> c2s >> s2;
        p1.emplace_back(valueOf(c1s), s1);
        p2.emplace_back(valueOf(c2s), s2);
    }
    vector<int> order(5);
    for (int i = 1; i <= 4; ++i) {
        int su; cin >> su;
        order[su] = i;
    }
    rearrange(p1, order);
    rearrange(p2, order);
    deque<pair<int,int>> deck1(p1.begin(), p1.end()), deck2(p2.begin(), p2.end());
    cout << playGame(deck1, deck2, order) << "\n";
    return 0;
}
