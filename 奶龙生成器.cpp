#include <bits/stdc++.h>
using namespace std;

// ==================== 内嵌模板 ====================
static const char *ART =
R"ART(
                         ..::::::::::::::..
                      .::::::::::::::::::::::.
                    :::::-::---------::::::::::..
                  .:------------------------::::::.
                 :------------------------------:::::..
                .----------====--------======-----:::::::..
                ----==========--=====+==========---:::::::::::..
               :--==========++=+#%@%%##*+========----:::::::::::::..
              .=-==+====++++++*%%#*****+++++++======------::::::::::::.
              .###*+++++++++++***********++++++++======-------:::::::::::.
               .*##%*+++++++++++++*******++++++++++========-------:::::::::.
                 =##*+++=======+++++*%%#**+++++++++++=========-------:::::::::.
                  -*++======+++****+%@@@*++++++++++++++=========--------:::::::.
                   :++****##***+**%@@@@@#+++++++++++++++=======----------::::::.
                     =#@@*###%@@@@@@@@@@#+++++++++++++++++++======---------:::::::.
                    . :+%@@@@@@@@@@@@@@@#+++******+++++++++++=======----------:::::.
                   :-  :+#@@@@%@@@@@@@%%#++***-=***++++++++++=======------------::--.
                  :-=-  :=+%@@#%@@@@@#*%*****: :***+++++++++++=========--------------.
                 -=====. .=+#@@%##*+*@@****+: .*****+++++++++++++==========-----------:
                :===++++:  :=*#%@@@@@#**+=:  -*******+++++++++++++++=========----------:.
               :==+++++++=:. .:=**#**=-. .:=**********++++++++++++++++==========---------.
              .-==+++**++++++-:  .:.  :-+##***********++++++++++**+++++===========--------.
              -==+++***-=++++++++++++***************++++++++++*****++++++==========--------.
             :==++++**#. =+++++++++++++++********+++++++++++++**#+ :+++++++==========-------:
             -==++++**#= .=+++++++++++++++++++++++++++++++++++***#. -++++++++==========------:
            :==++++****#- :++++++++++++++++++++++++++++++++++****##. =*++++++++============---:
            -=++++****### :++======================+++++++++++***###. +**+++++++===========----:
           .=+++*****##%@ .==================================++++**#* .***+++++++===========----:
           :=+*###%%%%@@@ .=====================================++**#=  :=****++++==========-----:
           :==++++*##%%@@ .======================================++*##*:    =++=====+++-::===-----.
           :-------=+*### .=-----===============================+++=:.  .::---====++++- .-====-----.
           .=-------=++** :=-----=============================+++=.  ::-----====++++++  -======----:
            ==-------==++  -================================+++=:  :---======++++++++: :========----.
            :===------==+= .=============================+++++:  .--=======+++++++*+. :===========--:
             -+===----==+*. =========================++++++=:  .-======++++++++***-  -+============--
              -++========+= .::......:====-.......::--=+=-:  :=====++++++++****+-. .=+++============-.
               :+++======++-::=+*##%: :===: =##**++=-:....:-==+++++++++*****=-.  :=+++++++===========.
                 -++++====+##%%@@%*=. :===- .=#@%%##**+===+++++++++*****=-. .:=+*++++++++++++========.
                  .-+++++*#%%%%@@:   .-==-:.  *%%%%##**+++++++*******+-. .=*#**++++++++++++++++======.
                    .-+**#%%%%%%%%#*+-::::-+*#%%%%%%%##***********+-. .-+****++++++++++++++++++++===-.
                       -*#%%%%%%%@%%%%@@%%%%%%%%%%%%%%###***+=:. .:-+****++++++++++++++++++++++++==.
                         -#%@@@@@%@@@@@@@@@@@@@@@@@@%%%%%*=:  .:=*****++++++++++++++++++++++++++++=-.
                           .+@@@@@@@%%@@@@@@@@@@@@@@@#+-  .-=****+++++++++++++++++++++++++++++++++=.
                             =%@@@@@@@@@@@@@@@@@@*=: .:-=****++++++++++++++++++++++++++++++++++++=.
                               :+%@@@@@@%*===#@*. :=+******+++++++++++++++++*****+++++++++++++++=.
                                  :+%%#*: :. :. :=*********************************++++++++++++=. 
                                 ...... .:*====+**********************************++++++++++++=.
                                   .+***********************************###******++++++++++++=.
                                .=-. :=*************************##########******++++++++++++-.
                                =***=:  :-+**************################*******+++++++++++=.
                               -****###+=:  :-=**#################%%%####********++++++++++-.
                              .****####%%%%#+-. ..:-=+**########%%%%%###************+++++++:.
                              =**######%%%%%%%@%#**+-::. .::::::--:. +###*****************+.
                              **######%%%%%%%%%%%%%%%%%*.            +####****************-.
                             .#######%%%%%%%%%%%%%%%%#-              =########************.
                             :#####%%%%%%%%%%%%%%%%%+.               .%###########*******+
                             :##%%%%%%%%%%%%%%%%%%+.                  *%#################-
                              #%%%%%%%%%%%%%%@@%*:                    :%%%%##############-
                              =%%%%%%%%%@@@@@@@@+                      +%%%%%%%%%%%%%%%###.
)ART";

static vector <string> BMP;
static int SH = 0, SW = 0;

static void loadArt() {
    BMP.clear();
    vector <string> raw;
    string cur;
    for (const char *p = ART; *p; p++) {
        if (*p == '\n') { raw.push_back(cur); cur.clear(); }
        else cur += *p;
    }
    if (!cur.empty()) raw.push_back(cur);
    while (!raw.empty() && raw.front().find_first_not_of(" \t") == string::npos) raw.erase(raw.begin());
    while (!raw.empty() && raw.back().find_first_not_of(" \t") == string::npos) raw.pop_back();
    SH = (int)raw.size();
    for (size_t i = 0; i < raw.size(); i++) SW = max(SW, (int)raw[i].size());
    for (int y = 0; y < SH; y++) {
        string line = raw[y];
        while ((int)line.size() < SW) line += ' ';
        string out(SW, ' ');
        for (int x = 0; x < SW; x++) {
            char c = line[x];
            out[x] = (c == '.' || c == ':' || c == ' ') ? ' ' : '#';
        }
        BMP.push_back(out);
    }
}
static long long inkCells() {
    long long c = 0;
    for (int y = 0; y < SH; y++) for (int x = 0; x < SW; x++) if (BMP[y][x] == '#') c++;
    return c;
}
static vector <string> figure(int H, int W) {
    vector <string> g(H, string(W, ' '));
    for (int y = 0; y < H; y++) {
        int sy0 = (int)((long long)y * SH / H), sy1 = max(sy0 + 1, (int)((long long)(y + 1) * SH / H));
        for (int x = 0; x < W; x++) {
            int sx0 = (int)((long long)x * SW / W), sx1 = max(sx0 + 1, (int)((long long)(x + 1) * SW / W));
            int ink = 0, tot = 0;
            for (int sy = sy0; sy < sy1 && sy < SH; sy++)
                for (int sx = sx0; sx < sx1 && sx < SW; sx++) { tot++; if (BMP[sy][sx] == '#') ink++; }
            if (tot && ink * 2 >= tot) g[y][x] = '#';
        }
    }
    return g;
}
static int H_of(int W) { return max(8, (int)llround((double)SH / SW * W)); }

static vector <string> coarse(const vector <string> &lines) {
    vector <string> tk;
    string cur;
    for (size_t li = 0; li < lines.size(); li++) {
        const string &line = lines[li];
        for (size_t i = 0; i < line.size(); i++) {
            char c = line[i];
            if (c == '/' && i + 1 < line.size() && line[i + 1] == '/') break;
            if (c == '/' && i + 1 < line.size() && line[i + 1] == '*') {
                size_t j = line.find("*/", i + 2);
                if (j == string::npos) break;
                i = j + 1; continue;
            }
            if (c == '"' || c == '\'') {                 // 字符串/字符常量整体保留
                cur += c;
                size_t j = i + 1;
                while (j < line.size()) {
                    cur += line[j];
                    if (line[j] == '\\') { if (j + 1 < line.size()) cur += line[++j]; }
                    else if (line[j] == c) break;
                    j++;
                }
                i = j; continue;
            }
            if (isspace((unsigned char)c)) { if (!cur.empty()) { tk.push_back(cur); cur.clear(); } continue; }
            cur += c;
        }
        if (!cur.empty()) { tk.push_back(cur); cur.clear(); }
    }
    return tk;
}
static bool isOp(const string &s, size_t i, int &len) {
    static const char *ops[] = {"<<=", ">>=", "...", "<<", ">>", "<=", ">=", "==", "!=", "&&", "||",
                                "++", "--", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "->", "::", 0};
    for (int k = 0; ops[k]; k++) {
        size_t l = strlen(ops[k]);
        if (s.compare(i, l, ops[k]) == 0) { len = (int)l; return true; }
    }
    return false;
}

static vector <string> fine(const vector <string> &tk) {
    vector <string> out;
    for (size_t k = 0; k < tk.size(); k++) {
        const string &s = tk[k];
        size_t i = 0;
        while (i < s.size()) {
            if (s[i] == '"' || s[i] == '\'') {
                char q = s[i];
                size_t j = i + 1;
                while (j < s.size()) { if (s[j] == '\\') { j += 2; continue; } if (s[j] == q) { j++; break; } j++; }
                out.push_back(s.substr(i, j - i)); i = j; continue;
            }
            if (isalnum((unsigned char)s[i]) || s[i] == '_') {
                size_t j = i;
                while (j < s.size() && (isalnum((unsigned char)s[j]) || s[j] == '_')) j++;
                out.push_back(s.substr(i, j - i)); i = j; continue;
            }
            int len = 1;
            if (isOp(s, i, len)) { out.push_back(s.substr(i, len)); i += len; continue; }
            out.push_back(string(1, s[i])); i++;
        }
    }
    return out;
}

static int flow(const vector <string> &tk, int W, int H, int fromRow, vector <string> &rows,
                int *nextRow = 0, bool repeat = true) {
    vector <string> g = figure(H, W);
    size_t ti = 0;
    int y = fromRow, blocks = 0;
    while (ti < tk.size()) {
        if (y >= H) {
            if (!repeat) break;
            if (++blocks > 5000) break;
            y = 0;
        }
        vector <pair <int, int>> runs;
        for (int i = 0; i < W; ) {
            if (g[y][i] != '#') { i++; continue; }
            int j = i;
            while (j < W && g[y][j] == '#') j++;
            runs.push_back(make_pair(i, j - 1));
            i = j;
        }
        if (runs.empty()) { y++; continue; }
        string line;
        bool any = false;
        for (size_t r = 0; r < runs.size() && ti < tk.size(); r++) {
            int Lo = runs[r].first, Ro = runs[r].second, col = Lo;
            bool placed = false;
            while (ti < tk.size()) {
                int need = (int)tk[ti].size() + (col > Lo ? 1 : 0);
                if (col + need > Ro + 1) break;
                if (!placed) { if ((int)line.size() < Lo) line += string(Lo - line.size(), ' '); }
                else line += ' ';
                line += tk[ti]; col += need; placed = true; any = true; ti++;
            }
        }
        if (any) rows.push_back(line);
        y++;
    }
    int left = (int)(tk.size() - ti);
    if (nextRow) *nextRow = (y >= H ? 0 : y);
    if (left) {                                   // 兜底: 剩余 token 拼行, 保证代码完整
        string rest;
        for (; ti < tk.size(); ti++) { if (!rest.empty()) rest += ' '; rest += tk[ti]; }
        rows.push_back(rest);
    }
    return left;
}

struct Seg { string barrier; vector <string> lines; bool verbatim; };

int main(int argc, char **argv) {
    loadArt();
    string inName = "in.cpp", outName = "out.cpp";
    bool all = true;
    int forceW = 0;
    if (argc >= 2) inName = argv[1];
    if (argc >= 3) outName = argv[2];
    if (argc >= 4) all = (string(argv[3]) != "main");
    if (argc >= 5) forceW = atoi(argv[4]);

    printf("template %dx%d, ink=%lld\n", SW, SH, inkCells());
    printf("input : %s\noutput: %s   mode=%s  W=%s\n", inName.c_str(), outName.c_str(),
           all ? "all" : "main", forceW > 0 ? to_string(forceW).c_str() : "auto");

    ifstream in(inName.c_str());
    if (!in) { printf("cannot open %s -- put it in the same folder as art.exe\n", inName.c_str()); return 1; }
    vector <string> L;
    string s;
    while (getline(in, s)) { if (!s.empty() && s.back() == '\r') s.pop_back(); L.push_back(s); }
    int N = (int)L.size();

    int headEnd = -1;
    vector <Seg> segs;
    if (!all) {
        int head = -1, tail = -1;
        for (int i = 0; i < N; i++) if (L[i].find("int main") != string::npos) { head = i; break; }
        if (head < 0) { printf("int main not found, use all mode\n"); return 1; }
        for (int i = N - 1; i > head; i--) {
            string t = L[i];
            while (!t.empty() && isspace((unsigned char)t.back())) t.pop_back();
            if (t == "}") { tail = i; break; }
        }
        if (tail < 0) { printf("closing brace not found\n"); return 1; }
        headEnd = head;
        Seg a; a.verbatim = false; a.lines.assign(L.begin() + head + 1, L.begin() + tail);
        segs.push_back(a);
        Seg b; b.verbatim = true; b.lines.assign(L.begin() + tail, L.end());
        segs.push_back(b);
    } else {
        int last = -1;
        for (int i = 0; i < N; i++) {
            string t = L[i];
            while (!t.empty() && isspace((unsigned char)t.front())) t.erase(t.begin());
            if (t.empty() || t[0] == '#' || t.rfind("//", 0) == 0 ||
                t.rfind("using namespace", 0) == 0 || t.rfind("using std::", 0) == 0) { last = i; continue; }
            break;
        }
        headEnd = last;
        Seg cur; cur.verbatim = false;
        for (int i = headEnd + 1; i < N; i++) {
            string t = L[i];
            while (!t.empty() && isspace((unsigned char)t.front())) t.erase(t.begin());
            if (!t.empty() && t[0] == '#') { segs.push_back(cur); cur = Seg(); cur.barrier = L[i]; }
            else cur.lines.push_back(L[i]);
        }
        segs.push_back(cur);
    }

    long long ink = 0;
    vector <vector <string>> toks(segs.size());
    for (size_t k = 0; k < segs.size(); k++) {
        if (segs[k].verbatim) continue;
        toks[k] = fine(coarse(segs[k].lines));
        for (size_t i = 0; i < toks[k].size(); i++) ink += (long long)toks[k][i].size() + 1;
    }
    vector <string> tkAll;
    for (size_t k = 0; k < segs.size(); k++) {
        if (segs[k].verbatim) continue;
        for (size_t i = 0; i < toks[k].size(); i++) tkAll.push_back(toks[k][i]);
    }

    int W, H;
    if (forceW > 0) { W = forceW; H = H_of(W); }
    else {                                        // 自动: 能填满整个代码的最大画布
        int bw = 0;
        for (int w = 20; w <= 1200; w += 2) {
            int h = H_of(w);
            vector <string> tmp;
            if (flow(tkAll, w, h, 0, tmp, 0, false) == 0) { bw = w; break; }
        }
        if (!bw) bw = 1200;
        W = bw; H = H_of(W);
    }

    vector <string> outRows;
    int row = 0;
    for (size_t k = 0; k < segs.size(); k++) {
        if (!segs[k].barrier.empty()) outRows.push_back(segs[k].barrier);
        if (segs[k].verbatim) {
            for (size_t i = 0; i < segs[k].lines.size(); i++) outRows.push_back(segs[k].lines[i]);
            continue;
        }
        int nr = row;
        flow(toks[k], W, H, row, outRows, &nr);
        row = nr;
    }

    ofstream of(outName.c_str());
    if (!of) { printf("cannot write %s\n", outName.c_str()); return 1; }
    for (int i = 0; i <= headEnd; i++) of << L[i] << "\n";
    for (size_t i = 0; i < outRows.size(); i++) of << outRows[i] << "\n";
    printf("done: W=%d H=%d ink=%lld rows=%d (native %dx%d needs %lld)\n",
           W, H, ink, (int)outRows.size(), SW, SH, inkCells());
    printf("now compile %s to check it still works\n", outName.c_str());
    return 0;
}
