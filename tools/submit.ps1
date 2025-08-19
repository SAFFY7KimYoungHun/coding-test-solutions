param (
    [Parameter(Mandatory=$true)]
    [ValidateSet("boj", "pro", "sql")]
    [string]$type,

    [Parameter(Mandatory=$true)]
    [string]$num
)

switch ($type) {
    "boj" {
        $filename = ".\problems\boj\boj_$num.cpp"
        $msg = "Add: BOJ $num 풀이"
    }
    "pro" {
        $filename = ".\problems\programmers\pro_$num.cpp"
        $msg = "Add: Programmers $num 풀이"
    }
    "sql" {
        $filename = ".\problems\sql\sql_$num.sql"
        $msg = "Add: SQL $num 풀이"
    }
}

if (Test-Path $filename) {
    git add $filename
    git commit -m "$msg"
    git push origin main
    Write-Host "제출 완료: $msg"
} else {
    Write-Host "❌ 파일 없음: $filename"
}
