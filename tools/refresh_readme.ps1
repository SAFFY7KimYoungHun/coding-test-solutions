$readme = @()

$readme += "# 문제 풀이 현황 (로컬 확인용)"
$readme += ""

$readme += "## BOJ"
Get-ChildItem .\problems\boj\boj_*.cpp | ForEach-Object {
    $readme += "- $($_.BaseName)"
}

$readme += ""
$readme += "## Programmers"
Get-ChildItem .\problems\programmers\pro_*.cpp | ForEach-Object {
    $readme += "- $($_.BaseName)"
}

$readme += ""
$readme += "## SQL"
Get-ChildItem .\problems\sql\sql_*.sql | ForEach-Object {
    $readme += "- $($_.BaseName)"
}

$readme | Out-File -Encoding utf8 README_local.md
Write-Host "README_local.md 갱신 완료"
