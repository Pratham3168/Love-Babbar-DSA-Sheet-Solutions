// class Solution {
//   public:
//     int minimumDays(int S, int N, int M) {
//     // 1. If you can't even survive a normal day
//     if (N < M) return -1;

//     // 2. Check survival for first Sunday
//     if (S >= 7 && (N - M) * 6 < M) return -1;

//     // 3. Total food needed
//     int total = S * M;

//     // 4. Buying days (no Sundays)
//     int buyDays = S - (S / 7);

//     // 5. If total purchase not enough
//     if (buyDays * N < total) return -1;

//     // 6. Minimum days needed
//     return (total + N - 1) / N;
// }
// };