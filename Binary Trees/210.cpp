// class Node {
//     constructor(data) {
//         this.data = data;
//         this.left = this.right = null;
//     }
// }

// let temp = null;

// function kthAncestorDFS(root, node, k) {
//     // Base case
//     if (root == null)
//         return null;

//     if (root.data === node ||
//         (temp = kthAncestorDFS(root.left, node, k)) !== null ||
//         (temp = kthAncestorDFS(root.right, node, k)) !== null) {
//         if (k.value > 0)
//             k.value--;
//         else if (k.value === 0) {
//             // Print the kth ancestor
//             console.log("Kth ancestor is: " + root.data);

//             // Return null to stop further backtracking
//             return null;
//         }

//         // Return current node to previous call
//         return root;
//     }

//     return null;
// }

// // Utility function to create a new tree node
// function newNode(data) {
//     return new Node(data);
// }

// // Driver program to test above functions
// function main() {
//     // Let us create binary tree shown in above diagram
//     const root = newNode(1);
//     root.left = newNode(2);
//     root.right = newNode(3);
//     root.left.left = newNode(4);
//     root.left.right = newNode(5);

//     let k = { value: 2 };
//     const node = 5;

//     // Print kth ancestor of given node
//     const parent = kthAncestorDFS(root, node, k);

//     // Check if parent is not NULL, it means
//     // there is no Kth ancestor of the node
//     if (parent !== null)
//         console.log("-1");
// }

// main();