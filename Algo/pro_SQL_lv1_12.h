#pragma once
//이름은 오름차순, 날짜는 내림차순. 같은 이름일 시 다음 날짜 내림차순으로 연산됨.
SELECT ANIMAL_ID, NAME, DATETIME
FROM ANIMAL_INS
ORDER BY NAME ASC, DATETIME DESC