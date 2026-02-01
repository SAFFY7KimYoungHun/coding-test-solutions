-- [문제]
-- 제목: pcsql 기출 1회
-- 출처: Programmers SQL
-- 난이도:
--
-- [풀이]
--

SELECT ID, CREATOR, LIKES
FROM NEW_POSTS

UNION ALL

SELECT ID, CREATOR, 0 AS LIKES
FROM OLD_POSTS

ORDER BY ID DESC;