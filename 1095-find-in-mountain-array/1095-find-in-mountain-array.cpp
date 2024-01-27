/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int st = 1, en = mountainArr.length() - 2, mx = -1;
        while(st<=en) {
            int mid = (st+en)/2;
            int x = mountainArr.get(mid);
            int l = mountainArr.get(mid-1);
            int r = mountainArr.get(mid+1);

            if(l<x && x>r) {
                mx = mid;
                break;
            }
            else if(l<x && x<r) st = mid + 1;
            else en = mid - 1;
        }

        st = 0, en = mx;
        while(st<=en) {
            int mid = (st+en)/2;
            int x = mountainArr.get(mid);

            if(x == target) return mid;
            else if(x<target) st = mid+1;
            else en = mid-1;
        }

        st = mx+1, en = mountainArr.length()-1;
        while(st<=en) {
            int mid = (st+en)/2;
            int x = mountainArr.get(mid);

            if(x == target) return mid;
            else if(x>target) st = mid+1;
            else en = mid-1;   
        }

        return -1;
    }
};