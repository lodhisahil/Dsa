class StreamChecker {
public:
    struct Node {
        Node* child[26];
        bool isEnd;
        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    Node* root;
    string stream;
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (string word : words) {
            reverse(word.begin(), word.end());
            Node* curr = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (curr->child[index] == nullptr) {
                    curr->child[index] = new Node();
                }
                curr = curr->child[index];
            }
            curr->isEnd = true;
        }
    }
    bool query(char letter) {
        stream += letter;
        Node* curr = root;
        int start = max(0, (int)stream.size() - 200);
        for (int i = stream.size() - 1; i >= start; i--) {
            int index = stream[i] - 'a';
            if (curr->child[index] == nullptr) {
                return false;
            }
            curr = curr->child[index];
            if (curr->isEnd) {
                return true;
            }
        }
        return false;
    }
};