# [Platinum IV] Batch Scheduling - 5498 

[문제 링크](https://www.acmicpc.net/problem/5498) 

### 성능 요약

메모리: 3076 KB, 시간: 52 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍, 누적 합

### 제출 일자

2024년 2월 13일 16:29:41

### 문제 설명

<p>There is a sequence of N jobs to be processed on one machine. The jobs are numbered from 1 to N, so that the sequence is 1,2, …, N. The sequence of jobs must be partitioned into one or more batches, where each batch consists of consecutive jobs in the sequence. The processing starts at time 0. The batches are handled one by one starting from the first batch as follows. If a batch b contains jobs with smaller numbers than batch c, then batch b is handled before batch c. The jobs in a batch are processed successively on the machine. Immediately after all the jobs in a batch are processed, the machine outputs the results of all the jobs in that batch. The output time of a job j is the time when the batch containing j finishes.</p>

<p>A setup time S is needed to set up the machine for each batch. For each job i, we know its cost factor Fi and the time Ti required to process it. If a batch contains the jobs x, x+1, … , x+k, and starts at time t, then the output time of every job in that batch is t + S + (T<sub>x</sub> + T<sub>x+1</sub> + … + T<sub>x+k</sub>). Note that the machine outputs the results of all jobs in a batch at the same time. If the output time of job i is O<sub>i</sub>, its cost is O<sub>i</sub> × F<sub>i</sub>. For example, assume that there are 5 jobs, the setup time S = 1, (T<sub>1</sub>, T<sub>2</sub>, T<sub>3</sub>, T<sub>4</sub>, T<sub>5</sub>) = (1, 3, 4, 2, 1), and (F<sub>1</sub>, F<sub>2</sub>, F<sub>3</sub>, F<sub>4</sub>, F<sub>5</sub>) = (3, 2, 3, 3, 4). If the jobs are partitioned into three batches {1, 2}, {3}, {4, 5}, then the output times (O<sub>1</sub>, O<sub>2</sub>, O<sub>3</sub>, O<sub>4</sub>, O<sub>5</sub>) = (5, 5, 10, 14, 14) and the costs of the jobs are (15, 10, 30, 42, 56), respectively. The total cost for a partitioning is the sum of the costs of all jobs. The total cost for the example partitioning above is 153.</p>

<p>You are to write a program which, given the batch setup time and a sequence of jobs with their processing times and cost factors, computes the minimum possible total cost.</p>

### 입력 

 <p>Your program reads from standard input. The first line contains the number of jobs N, 1 ≤ N ≤ 10000. The second line contains the batch setup time S which is an integer, 0 ≤ S ≤ 50. The following N lines contain information about the jobs 1, 2, …, N in that order as follows. First on each of these lines is an integer T<sub>i</sub> , 1 ≤ T<sub>i</sub> ≤ 100, the processing time of the job. Following that, there is an integer F<sub>i</sub>, 1 ≤ F<sub>i</sub> ≤ 100, the cost factor of the job.</p>

### 출력 

 <p>Your program writes to standard output. The output contains one line, which contains one integer: the minimum possible total cost.</p>

