class Solution {
public:
    string reverseWords(string ss) {
        std::string s(ss);
        int from = 0;
        int end = s.size() - 1;
        int space_idx = findNextSpace(s, from, end);
        while (space_idx >= 0) {
            reverseWord(s, from, end);
            from = space_idx + 1;
            space_idx = findNextSpace(s, from, end);
        }
        return s;
    }
    
    int findNextSpace(string & s, int from, int end) {
         for (int i = from; i <= end; i++) {
             if (s[i] == " ") {
                 return i;
             };
         }
         return -1;
     }
    
    void reverseWord(string & s, int from, int end) {
        while (from < end) {
            swap(s[from], s[end]);
            from++;
            end--;
        }
    }
};