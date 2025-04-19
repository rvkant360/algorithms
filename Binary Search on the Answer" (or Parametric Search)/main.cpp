#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool isPossible(const std::vector<int> &books, int m, int maxPages) {
    int students = 1, currentSum = 0;
    for (int pages : books) {
        if (pages > maxPages) return false;

        if (currentSum + pages > maxPages) {
            students++;
            currentSum = pages;
        } else {
            currentSum += pages;
        }
    }
    return students <= m;
}

int minPages(const std::vector<int> &books, int m) {
    if (books.size() < m) return -1;
    int low = *std::max_element(books.begin(), books.end());
    int high = std::accumulate(books.begin(), books.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(books, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    std::vector<int> books = {10, 20, 30, 40};
    int m = 2;
    std::cout << "Minimum maximum pages: " << minPages(books, m) << std::endl;
    return 0;
}
