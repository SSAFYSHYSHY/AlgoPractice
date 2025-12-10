#pragma once
//개수 판별.
//count(*) : count로 이름 갱신 ,group by name : 으로 name 만 , having count(*) >= n : n개의 이상에 대해서
SELECT NAME, COUNT(*) AS COUNT
FROM ANIMAL_INS
WHERE NAME IS NOT NULL
GROUP BY NAME
HAVING COUNT(*) >= 2
ORDER BY NAME ASC