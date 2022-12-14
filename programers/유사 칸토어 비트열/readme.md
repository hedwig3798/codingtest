# 유사 칸토어 비트열
### lv.2
수학에서 칸토어 집합은 0과 1 사이의 실수로 이루어진 집합으로, [0, 1]부터 시작하여 각 구간을 3등분하여 가운데 구간을 반복적으로 제외하는 방식으로 만들어집니다.

남아는 칸토어 집합을 조금 변형하여 유사 칸토어 비트열을 만들었습니다. 유사 칸토어 비트열은 다음과 같이 정의됩니다.

* 0 번째 유사 칸토어 비트열은 "1" 입니다.
* n(1 ≤ n) 번째 유사 칸토어 비트열은 n - 1 번째 유사 칸토어 비트열에서의 1을 11011로 치환하고 0을 00000로 치환하여 만듭니다.

남아는 `n` 번째 유사 칸토어 비트열에서 특정 구간 내의 1의 개수가 몇 개인지 궁금해졌습니다.
`n`과 1의 개수가 몇 개인지 알고 싶은 구간을 나타내는 `l`, `r`이 주어졌을 때 그 구간 내의 1의 개수를 return 하도록 solution 함수를 완성해주세요.
- - -
### 제한사항
* 1 ≤ `n` ≤ 20
* 1 ≤ `l`, `r` ≤ 5<sup>`n`</sup>
  * `l` ≤ `r` < `l` + 10,000,000
  * `l`과 `r`은 비트열에서의 인덱스(1-base)이며 폐구간 [l, r]을 나타냅니다.
- - - 
### 소감
문제가 직관적으로 이해되지 않아 조금 해맸다.   
하지만 유사 칸토어 비트열이 5 단위로 분열하고 중앙값을 중심으로 0이 퍼져나가는 그림이 그려졌다.   
결국 n번째 라인부터 5씩 나누어 윗 n-1 라인중 어디에 있는지 파악하고 만일 그곳이 3이라면 0, 아니라면 더 윗 라인을 찾아가는 식으로 알고리즘을 만들어 풀었다.   
10번 문제만 풀지 않아져서 당황 했는데, 단순이 변수 형식을 long long 으로 맞추지 않아 오버플로우가 발생한 것이였다.
- - -
출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
