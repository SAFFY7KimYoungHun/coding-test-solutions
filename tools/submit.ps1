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

# 경로 / 파일명 결정
switch ($type) {
    "bak" {
        $basePath = "study_Coding_Test\Baekjoon\$year\$month\$day"
        $filePath = "$basePath\bak_$name.cpp"
        $titlePattern = "- 제목:"
        $levelPattern = "- 난이도:"
    }

    "pro" {
        $basePath = "study_Coding_Test\Programmers\$year\$month\$day"
        $filePath = "$basePath\pro_$name.cpp"
        $titlePattern = "- 제목:"
        $levelPattern = "- 난이도:"
    }

    "sql" {
        $basePath = "study_SQL\Programmers\$year\$month\$day"
        $filePath = "$basePath\sql_$name.sql"
        $titlePattern = "제목:"
        $levelPattern = "난이도:"
    }
}

# 파일 존재 확인
if (!(Test-Path $filePath)) {
    Write-Host "❌ 파일을 찾을 수 없습니다:"
    Write-Host "   $filePath"
    exit 1
}

# 파일 내용 읽기
$content = Get-Content $filePath -Raw

# 제목 검사
if ($content -notmatch "$titlePattern\s*\S+") {
    Write-Host "❌ 제출 차단: 문제 제목이 비어 있습니다."
    Write-Host "👉 [$titlePattern] 항목을 채우세요."
    exit 1
}

# 난이도 검사
if ($content -notmatch "$levelPattern\s*\S+") {
    Write-Host "❌ 제출 차단: 난이도가 비어 있습니다."
    Write-Host "👉 [$levelPattern] 항목을 채우세요."
    exit 1
}

# Git 처리
git add $filePath
$commitMsg = "solve($type): $name"
git commit -m $commitMsg
git push origin main

Write-Host "✅ 제출 완료"
Write-Host "📄 $filePath"
Write-Host "📝 commit: $commitMsg"