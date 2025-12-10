#pragma once
//name 에 '%특정문자%' 포함 과 animal_type = '특정유형' 일 경우.
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME LIKE '%EL%' AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME ASC