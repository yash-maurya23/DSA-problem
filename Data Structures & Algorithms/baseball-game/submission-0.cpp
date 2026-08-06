class Solution {
   public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (const string& op : operations) {
            if (op == "+") {
                int size = record.size();
                record.push_back(record[size - 1] + record[size - 2]);
            } else if (op == "D") {
                record.push_back(2 * record.back());
            } else if (op == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(op));
            }
        }

        return accumulate(record.begin(), record.end(), 0);
    }
};