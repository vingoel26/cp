# commit.ps1

# Stage all changes
git add .

# Get list of staged C++ files
$files = git diff --cached --name-only -- '*.cpp'

if (-not $files) {
    Write-Host "No .cpp files staged. Exiting."
    exit 1
}

# Commit with file names in message
$commitMessage = "solved: $files"
git commit -m "$commitMessage"

# Push changes
git push
