class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        results = []
        for rows in range(numRows):
            # size = rows + 1
            # begining and end are 1
            row = [1] * (rows + 1)
            for cols in range(1, rows):
                # dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                row[cols] = results[rows-1][cols-1] + results[rows-1][cols]
            results.append(row)
            
        return results
