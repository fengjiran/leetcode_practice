#include "utils.h"
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> aux;

public:
    vector<int> sortArray(vector<int>& nums) {
        //        selectionSort(nums);
        //        insertionSort(nums);
        //        binaryInsertSort(nums);
        int n = (int) nums.size();
        aux.resize(n);
        mergeSortImprovement(nums, 0, n - 1);
        return nums;
    }

    void mergeSortImprovement(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        if (right - left + 1 <= 7) {
            for (int i = left + 1; i <= right; i++) {
                int pivot = nums[i];
                int j = i - 1;
                while (j >= 0 && nums[j] > pivot) {
                    nums[j + 1] = nums[j];
                    j--;
                }
                nums[j + 1] = pivot;
            }
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        if (nums[mid] <= nums[mid + 1]) {
            return;
        }
        merge(nums, left, mid, right);
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            aux[i] = nums[i];
        }

        int i = left;
        int j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                nums[k] = aux[j++];
            } else if (j == right + 1) {
                nums[k] = aux[i++];
            } else if (aux[i] > aux[j]) {
                nums[k] = aux[j++];
            } else {
                nums[k] = aux[i++];
            }
        }
    }

    static void selectionSort(vector<int>& nums) {
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            int idx = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[idx]) {
                    idx = j;
                }
            }
            std::swap(nums[i], nums[idx]);
        }
    }

    static void binaryInsertSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int pivot = nums[i];
            int left = 0;
            int right = i;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < pivot) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            for (int j = i - 1; j >= left; j--) {
                nums[j + 1] = nums[j];
            }
            nums[left] = pivot;
        }
    }

    static void insertionSort(vector<int>& nums) {
        int n = (int) nums.size();
        for (int i = 1; i < n; i++) {
            int pivot = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > pivot) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = pivot;
        }
    }

    static void insertionSort1(vector<int>& nums) {
        int n = (int) nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--) {
                std::swap(nums[j], nums[j - 1]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
