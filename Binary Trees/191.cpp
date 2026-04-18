// // JavaScript program to print diagonal view

// class Node {
//     constructor(x) {
//         this.key = x;
//         this.left = null;
//         this.right = null;
//     }
// }

// // Recursive function to print diagonal view
// function diagonalRecur(root, level, levelData) {

//     // Base case
//     if (root === null)
//         return;

//     // Append the current node into hash map.
//     if (!levelData[level]) {
//         levelData[level] = [];
//     }
//     levelData[level].push(root.key);

//     // Recursively traverse the left subtree.
//     diagonalRecur(root.left, level + 1, levelData);

//     // Recursively traverse the right subtree.
//     diagonalRecur(root.right, level, levelData);
// }

// // function to print diagonal view
// function diagonal(root) {
//     let ans = [];

//     // Create a hash map to store each
//     // node at its respective level.
//     let levelData = {};
//     diagonalRecur(root, 0, levelData);

//     let level = 0;

//     // Insert into answer level by level.
//     while (level in levelData) {
//         ans = ans.concat(levelData[level]);
//         level++;
//     }

//     return ans;
// }

// function printList(v) { console.log(v.join(" ")); }

// // Create a hard coded tree
// //         8
// //       /   \
// //     3      10
// //    /      /  \
// //   1      6    14
// //         / \   /
// //        4   7 13
// let root = new Node(8);
// root.left = new Node(3);
// root.right = new Node(10);
// root.left.left = new Node(1);
// root.right.left = new Node(6);
// root.right.right = new Node(14);
// root.right.right.left = new Node(13);
// root.right.left.left = new Node(4);
// root.right.left.right = new Node(7);

// let ans = diagonal(root);
// printList(ans);