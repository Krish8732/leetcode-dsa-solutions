# Setup & Next Steps

## ✅ What's Ready

Your **LeetCode DSA Solutions** repository structure is ready at:
```
C:\Users\krish\Desktop\leetcode-dsa-solutions\
```

### Folder Structure Created:
- ✅ 21 Topic folders (Arrays, Strings, Tree, Graph, DP, etc.)
- ✅ Each topic has Easy, Medium, Hard subfolders
- ✅ Sample solution: `Tree/Medium/938_RangeSumOfBST.cpp`
- ✅ README.md with overview
- ✅ .gitignore for common files

---

## 🚀 Next Steps to Push to GitHub

### 1. **Install Git** (if not already installed)
   - Download from: https://git-scm.com/download/win
   - Install with default settings
   - Restart your terminal/PowerShell

### 2. **Initialize Git Repository**
   ```powershell
   cd C:\Users\krish\Desktop\leetcode-dsa-solutions
   git init
   git config user.name "YourGitHubUsername"
   git config user.email "your.email@example.com"
   git add .
   git commit -m "Initial commit: Create DSA folder structure with 21 topics"
   ```

### 3. **Create GitHub Repository**
   - Go to https://github.com/new
   - Repository name: `leetcode-dsa-solutions`
   - Description: `Organized LeetCode and DSA problem solutions by topic and difficulty`
   - Choose: Public (so others can see)
   - Click "Create repository"

### 4. **Connect Local to GitHub**
   ```powershell
   git remote add origin https://github.com/YourUsername/leetcode-dsa-solutions.git
   git branch -M main
   git push -u origin main
   ```

### 5. **Add Sample Solution & Commit**
   ```powershell
   git add Tree/Medium/938_RangeSumOfBST.cpp
   git commit -m "Tree/Medium: 938 Range Sum of BST"
   git push
   ```

---

## 📋 Commit Message Format

Always use this format for clarity:

```
[Topic/Difficulty]: [LeetCode #] [Problem Name]

Optional description
```

### Examples:
```
Tree/Medium: 938 Range Sum of BST
Arrays/Easy: 1 Two Sum
Graph/Hard: 127 Word Ladder
DP/Medium: 377 Combination Sum IV
```

---

## 📝 How to Add Your Solutions

For each new problem you solve:

1. **Place the file** in the correct folder:
   ```
   [Topic]/[Difficulty]/[LeetCode#]_[ProblemName].cpp
   ```

2. **Keep the file lightweight**
   - LeetCode link at the top
   - DSA concepts
   - Short approach
   - Time Complexity
   - Space Complexity
   - Only the `class Solution` code you submitted on LeetCode

3. **Commit with meaningful message**:
   ```powershell
   git add Tree/Medium/939_MinimumAreaRectangle.cpp
   git commit -m "Tree/Medium: 939 Minimum Area Rectangle"
   git push
   ```

---

## 🎯 Quick Checklist for Each Solution

Before committing:
- [ ] File in correct topic folder
- [ ] File in correct difficulty level
- [ ] Filename follows convention: `[Number]_[Name].cpp`
- [ ] File includes: LeetCode link, concepts, approach, TC, SC
- [ ] File contains only the solution class code, not the full problem statement
- [ ] Code is tested and works on LeetCode
- [ ] Commit message is meaningful and follows format

---

## 💡 Tips

1. **Keep files organized** - don't mix difficulties in the same folder
2. **Update README** when adding new topics or reaching milestones
3. **Include comments** for complex logic
4. **Test thoroughly** before committing
5. **Push regularly** to avoid losing work

---

## 📚 Resources

- **LeetCode**: https://leetcode.com/
- **CodeStoryWithMik**: https://www.youtube.com/@codestorywithmik

---

**Your repository is all set! Start adding solutions and build your learning resource.** 🚀
