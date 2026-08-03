class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        # build adjacency list
        graph = [[] for _ in range(n+1)]
        for s, t, v in times:
            graph[s].append((t, v))

        # create distance array
        INT_MAX = 1e9
        minDist = [INT_MAX] * (n+1)

        # optimized: if the element is in the queue, don't append twice
        InQueue = [False] * (n+1)

        # queue optimized bellmen ford
        q = deque()
        q.append(k)
        minDist[k] = 0
        InQueue[k] = True

        while q:    # !q.empty()
            src = q.popleft()
            InQueue[src] = False

            # relax all outgoing edges
            for t, v in graph[src]:
                # update the neighbor
                if minDist[src] + v < minDist[t]:
                    minDist[t] = minDist[src] + v
                    if not InQueue[t]:
                        InQueue[t] = True
                        q.append(t)

        ans = 0
        for i in range(1, n+1):
           
            if minDist[i] == INT_MAX:
                return -1

            ans = max(ans, minDist[i])

        return ans
