param (
    [Parameter(Mandatory=$true)]
    [ValidateSet("bak", "pro", "sql")]
    [string]$type,

    [Parameter(Mandatory=$true)]
    [string]$name
)

# 오늘 날짜
$now = Get-Date
$year  = $now.ToString("yyyy")
$month = $now.ToString("MM")
$day   = $now.ToString("dd")

# 경로 + 확장자 + 헤더 설정
switch ($type) {
    "bak" {
        $basePath = "study_Coding_Test\Baekjoon\$year\$month\$day"
        $filename = "bak_$name.cpp"
        $header = @"
/*
[문제]
- 제목:
- 출처: Baekjoon
- 난이도:

[풀이]
-
*/
"@
    }

    "pro" {
        $basePath = "study_Coding_Test\Programmers\$year\$month\$day"
        $filename = "pro_$name.cpp"
        $header = @"
/*
[문제]
- 제목:
- 출처: Programmers
- 난이도:

[풀이]
-
*/
"@
    }

    "sql" {
        $basePath = "study_SQL\Programmers\$year\$month\$day"
        $filename = "sql_$name.sql"
        $header = @"
-- [문제]
-- 제목:
-- 출처: Programmers SQL
-- 난이도:
--
-- [풀이]
--
"@
    }
}

# 폴더 없으면 생성
if (!(Test-Path $basePath)) {
    New-Item -ItemType Directory -Path $basePath -Force | Out-Null
}

# 파일 경로
$filePath = Join-Path $basePath $filename

# 파일 생성
if (Test-Path $filePath) {
    Write-Host "⚠ 이미 파일이 존재합니다: $filePath"
} else {
    $header | Out-File -Encoding utf8 $filePath
    Write-Host "✅ 파일 생성 완료:"
    Write-Host "   $filePath"
}