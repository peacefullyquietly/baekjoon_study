// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.Arrays;
// import java.util.StringTokenizer;
// import java.io.BufferedWriter;
// import java.io.IOException;
// import java.io.OutputStreamWriter;

// public class Main {
//     public static void main(String[] args) throws IOException{
//         InputReader io = new InputReader();
//         BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

//         int n = io.nextInt();
//         int[] arr = new int[10];

//         while(n>0){
//             arr[n%10]++;
//             n /= 10;
//         }

//         arr[6] = (arr[6] + arr[9] + 1) / 2;
//         arr[9] = 0;

//         bw.write(String.valueOf(Arrays.stream(arr).max().orElse(0)));
//         bw.flush();
//         bw.close();
//     }
// }

// class InputReader {
//     public BufferedReader reader;
//     public StringTokenizer st;

//     public InputReader() {
//         reader = new BufferedReader(new InputStreamReader(System.in));
//     }

//     public String next() {
//         while (st == null || !st.hasMoreTokens()) {
//             st = new StringTokenizer(nextLine());
//         }
//         return st.nextToken();
//     }

//     public String nextLine() {
//         try {
//             return reader.readLine();
//         } catch (IOException e) {
//             e.printStackTrace();
//         }
//         return null;
//     }

//     public int nextInt() {
//         return Integer.parseInt(next());
//     }
// }