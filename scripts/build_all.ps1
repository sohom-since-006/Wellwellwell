<#
.SYNOPSIS
    Build automation script for compiling C and C++ laboratory programs.
.DESCRIPTION
    Scans the repository for .cpp and .c files, compiles them using g++ or gcc,
    and outputs binaries into a bin/ directory.
#>

param(
    [string]$Compiler = "g++",
    [string]$OutputDir = "bin",
    [string]$Target = "all"
)

$ErrorActionPreference = "Stop"

if (-not (Test-Path $OutputDir)) {
    New-Item -ItemType Directory -Path $OutputDir | Out-Null
    Write-Host "Created output directory: $OutputDir" -ForegroundColor Cyan
}

$compilerPath = Get-Command $Compiler -ErrorAction SilentlyContinue
if (-not $compilerPath) {
    Write-Warning "Compiler '$Compiler' was not found in PATH. Please install MinGW or GCC."
    exit 1
}

Write-Host "Using compiler: $($compilerPath.Source)" -ForegroundColor Green

$sourceFiles = Get-ChildItem -Path . -Filter "*.cpp" -File
Write-Host "Found $($sourceFiles.Count) C++ source files." -ForegroundColor Cyan

$successCount = 0
$failCount = 0

foreach ($file in $sourceFiles) {
    $outName = [System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".exe"
    $outPath = Join-Path $OutputDir $outName

    Write-Host "Compiling: $($file.Name) -> $outName" -NoNewline
    try {
        & $Compiler -std=c++17 -Wall -Wextra "$($file.FullName)" -o "$outPath" 2>&1 | Out-Null
        Write-Host " [OK]" -ForegroundColor Green
        $successCount++
    }
    catch {
        Write-Host " [FAILED]" -ForegroundColor Red
        $failCount++
    }
}

Write-Host "Build finished: $successCount succeeded, $failCount failed." -ForegroundColor ($failCount -gt 0 ? 'Yellow' : 'Green')
