# 가장 긴 팰린드롬

### lv.3
<div class="guide-section-description">
      <h6 class="guide-section-title">문제 설명</h6>
      <div class="markdown solarized-dark"><p>앞뒤를 뒤집어도 똑같은 문자열을 팰린드롬(palindrome)이라고 합니다.<br>
문자열 s가 주어질 때, s의 부분문자열(Substring)중 가장 긴 팰린드롬의 길이를 return 하는 solution 함수를 완성해 주세요.</p>

<p>예를들면, 문자열 s가 "abcdcba"이면 7을 return하고 "abacde"이면 3을 return합니다.</p>

<h5>제한사항</h5>

<ul>
<li>문자열 s의 길이 : 2,500 이하의 자연수</li>
<li>문자열 s는 알파벳 소문자로만 구성</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>s</th>
<th>answer</th>
</tr>
</thead>
        <tbody><tr>
<td>"abcdcba"</td>
<td>7</td>
</tr>
<tr>
<td>"abacde"</td>
<td>3</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
4번째자리 'd'를 기준으로 문자열 s 전체가 팰린드롬이 되므로 7을 return합니다.</p>

<p>입출력 예 #2<br>
2번째자리 'b'를 기준으로 "aba"가 팰린드롬이 되므로 3을 return합니다.</p>
</div>
    </div>
    
- - -
### 소감

함수형 프로그래밍의 단점을 체험한 문제이다.   
특별한 알고리즘 없이 문제를 있는 그대로 최대한 빠르게 푸는것이 관건인 문제이다.   
처음에는 팬듈럼인지 체크하는 함수를 만들어 실행을 하였는데 계속 효율성 1번이 시간초과가 나오게 되었다.   
그 결과 다른사람들의 풀이를 여러개 찾아보았고, 알고리즘이 나와 동일하게 문제를 풀은 사람이 여럿 보였다.   
결국 팬듈럼 체크 부분을 함수를 만들지 않고 직접 반복문에 적어 통과하게 되었다.   
시간 제한이 엄청 빡빡하게 짜여져 있어서 이러한 문제가 발생 한 것 같다.
- - -
출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
