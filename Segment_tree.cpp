#include <stdio.h>

struct segment_tree {
    //other..  ->cnt = how many times these section have been select
    //         ->ln = how long these section have been select
    int cnt,ln;

    //tree object
    int left, mid, right;
    struct segment_tree *lc, *rc;
};

void build (struct segment_tree *root,int left,int right) {
    //build the tree -> use 2N space
    root->left = left;
    root->right = right;
    root->mid = (left + right) / 2;
    if (left == right)    return;

    root->lc = new struct segment_tree();
    root->rc = new struct segment_tree();

    build(root->lc, left, root->mid);
    build(root->rc, root->mid + 1, right);
}

void print_tree (struct segment_tree *root) {
    printf("[%d %d] %d %d\n", root->left, root->right,root->cnt,root->ln);
    if (root->lc==NULL||root->rc==NULL) return;
    print_tree(root->lc);
    print_tree(root->rc);
}

void insert(struct segment_tree *root,int left,int right)  {
    if (root->left==left && root->right==right )    {
        root->cnt++;
        root->ln = right - left + 1;
        return;
    }

    if    (right<=root->mid)
        insert(root->lc,left,right);
    else  if (left > root->mid)
        insert(root->rc, left, right);
    else  {
        insert(root->lc, left, root->mid);
        insert(root->rc, root->mid+1, right);
    }

    if (root->cnt==0)
        root->ln = root->lc->ln + root->rc->ln;
}

void del(struct segment_tree *root, int left, int right) {
    if (root->left==left && root->right==right ) {
        root->cnt--;
        if (root->cnt==0)
            if (left==right)
                root->ln = 0;
            else
                root->ln = root->lc->ln + root->rc->ln;
    return;
    }

    if    (right<=root->mid)
        del(root->lc,left,right);
    else  if (left > root->mid)
        del(root->rc, left, right);
    else  {
        del(root->lc, left, root->mid);
        del(root->rc, root->mid+1, right);
    }

    if (root->cnt==0)
        root->ln = root->lc->ln + root->rc->ln;
}

int main () {
    struct segment_tree *root=new struct segment_tree();

    build(root, 0, 10);
    insert(root, 5, 10);
    insert(root, 1, 8);
    del(root, 5, 10);

    print_tree(root);
    return 0;
}
