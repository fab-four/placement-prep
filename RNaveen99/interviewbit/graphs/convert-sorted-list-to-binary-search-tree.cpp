/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
 */

TreeNode *arrayToBST(vector<int> &arr, int lo, int hi) {
    if (lo > hi) {
        return NULL;
    }
    int mid = lo + (hi - lo) / 2;
    TreeNode *curr = new TreeNode(arr[mid]);
    curr->left = arrayToBST(arr, lo, mid - 1);
    curr->right = arrayToBST(arr, mid + 1, hi);
    return curr;
}

TreeNode *Solution::sortedListToBST(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    vector<int> arr;
    while (head != NULL) {
        arr.push_back(head->val);
        head = head->next;
    }
    return arrayToBST(arr, 0, arr.size() - 1);
}

// ------------------------------------------------------------------------------------
TreeNode *makeTree(ListNode *&head, int start, int end) {
    if (start > end)
        return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode *left = makeTree(head, start, mid - 1);
    TreeNode *root = new TreeNode(head->val);
    head = head->next;
    TreeNode *right = makeTree(head, mid + 1, end);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode *Solution::sortedListToBST(ListNode *A) {
    if (!A)
        return 0;
    int len = 0;
    for (ListNode *curr = A; curr; curr = curr->next)
        len++;
    return makeTree(A, 0, len - 1);
}