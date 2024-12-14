import java.io.*
import java.util.*

object Main {
    @Throws(IOException::class)
    @JvmStatic
    fun main(args: Array<String>) {
        val io = InputReader()
        val bw = BufferedWriter(OutputStreamWriter(System.out))
        var n = io.nextInt()
        val arr = IntArray(10)
        while (n > 0) {
            arr[n % 10]++
            n /= 10
        }
        arr[6] = (arr[6] + arr[9] + 1) / 2
        arr[9] = 0
        bw.write(Arrays.stream(arr).max().orElse(0).toString())
        bw.flush()
        bw.close()
    }
}

internal class InputReader {
    var reader: BufferedReader
    var st: StringTokenizer? = null

    init {
        reader = BufferedReader(InputStreamReader(System.`in`))
    }

    operator fun next(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(nextLine())
        }
        return st!!.nextToken()
    }

    fun nextLine(): String? {
        try {
            return reader.readLine()
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return null
    }

    fun nextInt(): Int {
        return next().toInt()
    }
}