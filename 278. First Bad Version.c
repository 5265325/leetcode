// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(isBadVersion(1)) {
        return 1;
    }
    int left = 1, right = n;
    while (left < right) {
        int mid = left / 2 + right / 2;
        if (isBadVersion(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}