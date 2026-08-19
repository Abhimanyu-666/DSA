class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;

        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << col);
            }
        }

        int result = (n - (int)rowMask.size()) * 2;

        int leftBlock  = 0b1111 << 2; // bits 2,3,4,5
        int midBlock   = 0b1111 << 4; // bits 4,5,6,7
        int rightBlock = 0b1111 << 6; // bits 6,7,8,9

        for (auto& [row, mask] : rowMask) {
            bool leftFree = (mask & leftBlock) == 0;
            bool rightFree = (mask & rightBlock) == 0;
            bool midFree = (mask & midBlock) == 0;

            if (leftFree && rightFree) {
                result += 2;
            } else if (leftFree || rightFree || midFree) {
                result += 1;
            }
        }

        return result;
    }
};