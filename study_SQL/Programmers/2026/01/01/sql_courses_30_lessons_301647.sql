-- [문제]
-- 제목: 부모의 형질을 모두 가지는 대장균 찾기
-- 출처: Programmers SQL
-- 난이도: 2
--
-- [풀이]
--
-- 코드를 작성해주세요
select C.ID, C.GENOTYPE,  P.GENOTYPE as PARENT_GENOTYPE 
from ECOLI_DATA C
left join ECOLI_DATA P
    ON C.PARENT_ID = P.ID
where C.GENOTYPE&P.GENOTYPE=P.GENOTYPE
order by ID asc;