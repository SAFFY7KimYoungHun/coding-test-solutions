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
        if (!(Test-Path $filename)) {
            "/* BOJ $num */" | Out-File -Encoding utf8 $filename
        }
        Write-Host "생성됨: $filename"
    }
    "pro" {
        $filename = ".\problems\programmers\pro_$num.cpp"
        if (!(Test-Path $filename)) {
            "/* Programmers $num */" | Out-File -Encoding utf8 $filename
        }
        Write-Host "생성됨: $filename"
    }
    "sql" {
        $filename = ".\problems\sql\sql_$num.sql"
        if (!(Test-Path $filename)) {
            "-- SQL 문제 $num" | Out-File -Encoding utf8 $filename
        }
        Write-Host "생성됨: $filename"
    }
}
