#pragma once
//카운트를 주고, 어디에서 가져올지, 나이가 공백인 경우
SELECT COUNT(*)
FROM USER_INFO AS USERS
WHERE AGE IS NULL