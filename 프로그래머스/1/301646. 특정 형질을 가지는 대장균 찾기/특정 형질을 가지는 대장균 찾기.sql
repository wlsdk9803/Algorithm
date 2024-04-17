-- 1번 형질: 2로 나눈 나머지가 1이면 있음
-- 2번 형질: 4로 나눈 나머지가 2 또는 3이면 있음
-- 3번 형질: 8로 나눈 나머지가 7, 6, 5, 4이면 있음

SELECT COUNT(*) AS COUNT FROM ECOLI_DATA
WHERE GENOTYPE % 4 NOT IN (2, 3) AND (GENOTYPE % 2 = 1 OR GENOTYPE % 8 IN (4, 5, 6, 7));