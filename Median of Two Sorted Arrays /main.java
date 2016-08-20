public class Solution {
    
    public int[] truncat(int[] nums, int n) {
        int[] rst = new int[nums.length - n];
        
        for (int i = n; i < nums.length; i++) {
            rst[i-n] = nums[i];
        }
        
        return rst;
    }
    
    public double findKth(int[] nums1, int[] nums2, int k) {
        int m = nums1.length;
        int n = nums2.length;
        
        if (m > n) {
            return findKth(nums2, nums1, k);
        }
        
        if (m == 0) {
            return nums2[k-1];
        }
        
        if (k == 1) {
            return Math.min(nums1[0], nums2[0]);
        }
        
        int pa = Math.min(k/2, m);
        int pb = k - pa;
        
        if (nums1[pa - 1] > nums2[pb - 1]) {
            return findKth(nums1, truncat(nums2, pb), k - pb);
        } else if (nums1[pa - 1] < nums2[pb - 1]) {
            return findKth(truncat(nums1, pa), nums2, k - pa);
        } else {
            return nums1[pa - 1];
        }
    }
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int total = nums1.length + nums2.length;
        
        if (total % 2 != 0) {
            return findKth(nums1, nums2, total/2 + 1);
        } else {
            return (findKth(nums1, nums2, total/2) + findKth(nums1, nums2, total/2 + 1)) / 2;
        }
    }
}
